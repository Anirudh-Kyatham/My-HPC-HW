/*  Nick Sweeting 2013/10/08
    Student List (OOP)
    MIT Lisence
    g++ Vectors.cpp -o main && ./main

    Example of using vectors to store a list of students and their GPAs.
    It is referred from: https://github.com/pirate/Cpp-Data-Structures/
*/

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Student {
    string firstName;
    string lastName;
    int studentID;
    double GPA;
};

void printStudents(vector<Student> students) {
    for(auto [fname,lname,sid,GPA] : students ){
        std::cout << " first name : " << fname << std::endl;
        std::cout << " last name : " << lname << std::endl;
        std::cout << " student ID : " << sid << std::endl;
        std::cout << " GPA : " << GPA << std::endl;
    }
}

vector<Student> addStudent(vector<Student> students) {

    Student newStudent;

    cout << "First Name: ";
    cin >> newStudent.firstName;
    cout << "Last Name: ";
    cin >> newStudent.lastName;
    cout << "ID: ";
    cin >> newStudent.studentID;
    cout << "GPA: ";
    cin >> newStudent.GPA;

    // complete the functions here ...
    students.insert(students.end(),std::move(newStudent));

    return students;
}

vector<Student> delStudent(vector<Student> students) {
    int studentIDtoDel;
    cout << "ID of student to delete: ";
    cin >> studentIDtoDel;

    cout << "ID to delete: " << studentIDtoDel << endl;

    vector<Student> newStudents{students};
    auto it=newStudents.begin();
    for(; it != newStudents.end(); ++it){
        if(it->studentID == studentIDtoDel){
            break;
        }
    }
    if(it == newStudents.end()){
        cout << "no matching ID found" << std::endl;
        return newStudents;
    }
    auto endit = newStudents.end();
    --endit;
    std::swap(*it, *endit);
    newStudents.pop_back();
    return newStudents;
}

int main() {
    vector<Student> students;
    string input;

    while (true) {
        cout<<"Input operation: ";
        cin >> input;

        if (input == "ADD" || input == "a" || input == "add") {
            students = addStudent(students);
        }
        else if (input == "PRINT" || input == "p" || input == "print") {
            printStudents(students);
        }
        else if (input == "DELETE" || input == "d" || input == "delete") {
            students = delStudent(students);
        }
        else if (input == "QUIT" || input == "q" || input == "quit") {
            return 0;
        }
    }
}
