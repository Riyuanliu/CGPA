//
//  main.cpp
//  CGPA
//
//  Created by Riyuan Liu on 7/6/23.
//


#include <iostream>
#include <fstream>
#include "Semester.hpp"
using namespace std;

//int main(){
//    cout<<"Welcome to cumulative grade point average."<<endl;
//    ifstream myfile("Allcourse.txt");
//    if (!myfile) {
//        ofstream MyFile("Allcourse.txt");
//
//        MyFile.close();
//        ifstream myfile("Allcourse.txt");
//    }
//    string line;
//    while(getline(myfile, line)){
//        cout << line << endl;
//    }
//    myfile.close();
//    return 0;
//}
int main() {
    Assignment assignment1("Test", 90.0, 0.2);
    Assignment assignment2("HW", 85.0, 0.3);

    Course course1("Math", "A", 3);
    course1.addAssignment(assignment1);
    course1.addAssignment(assignment2);

    Assignment assignment3("Assignment 1", 95.0, 0.2);
    Assignment assignment4("Assignment 2", 88.0, 0.3);

    Course course2("History", "B", 4);
    course2.addAssignment(assignment3);
    course2.addAssignment(assignment4);

    Semester semester("Fall 2023");
    semester.addCourse(course1);
    semester.addCourse(course2);

    std::cout << "Semester: " << semester.getName() << std::endl;
    std::cout << "GPA: " << semester.calculateGPA() << std::endl;

    return 0;
}
