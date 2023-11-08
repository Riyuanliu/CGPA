//
//  main.cpp
//  College GPA Calculator
//
//  Created by Riyuan Liu on 10/18/23.
//

#include <iostream>
#include <fstream>
#include "Semester.hpp"
void optain1(){
    
    std::cout<<"Enter amount of assignment                   :";
    int assignmentamount=0;
    std::string coursename="";
    std::cin>>assignmentamount;
    std::vector<Assignment> course1;
    std::cout<<"Enter the name of this Course                :";
    std::cin>>coursename;
    for(int i = 1;i<assignmentamount+1;i++){
        std::cout<<"Enter assignment "<<i<< " name                      :";
        std::string assignmentname="";
        std::cin>>assignmentname;
        std::cout<<"Enter your grade for assignment "<<i<< "            :";
        int assignmentgrade=0;
        std::cin>>assignmentgrade;
        std::cout<<"Enter the weight for assignment "<<i<< "            :";
        float assignmentweight=0;
        std::cin>>assignmentweight;
        Assignment assignment(assignmentname,assignmentgrade,assignmentweight);
        course1.push_back(assignment);
    }
    Course course(coursename);
    course.setAssignment(course1);
    course.printallassignment();
    std::cout<<"Your GPA for this Course is:"<<course.getLetterGrade()<<std::endl;
    
    
    
}
void optain2() {
    int numCourses;
    std::cout << "Enter the number of courses: ";
    std::cin >> numCourses;

    // Create a vector to store individual course GPAs
    Semester semester1("temp");

    for (int i = 0; i < numCourses; i++) {
        std::cout << "Course " << i + 1 << ":" << std::endl;
        optain1(); // Call your optain1() function to calculate GPA for each course
        Course course;
        std::cout << "Enter Your GPA for this Course"<< ":" << std::endl;
        int grade=0;
        std::cin>>grade;
        course.setNumbGrade(grade);
        semester1.addCourse(course);
    }

    std::cout << "Your Cumulative Grade Point Average (CGPA) is: " << semester1.calculateGPA()<< std::endl;
}
int main() {
    // Display a welcome message
    std::cout << "--------------------------------------------------------------------------" << std::endl;
    std::cout << "          Welcome to CGPA Calculator" << std::endl;
    std::cout << "--------------------------------------------------------------------------\n" << std::endl;

    // Display options
    std::cout << "What would you like to do:" << std::endl;
    std::cout << "1. Calculate the GPA for a single course" << std::endl;
    std::cout << "2. Calculate CGPA (Cumulative Grade Point Average)" << std::endl;
    std::cout << "3. Exit the Application" << std::endl;

    // Display a separator
    std::cout << "--------------------------------------------------------------------------" << std::endl;

    int choice;

    // Get user input
    std::cout << "Enter your choice (1/2/3): ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            // Add code to calculate GPA for a single course
            std::cout << "You selected option 1. Calculating GPA for a single course..." << std::endl;
            optain1();
            break;
        case 2:
            // Add code to calculate CGPA
            std::cout << "You selected option 2. Calculating CGPA (Cumulative GPA)..." << std::endl;
            optain2();
            break;
        case 3:
            // Exit the application
            std::cout << "Exiting the application. Goodbye!" << std::endl;
            break;
        default:
            // Handle invalid input
            std::cout << "Invalid choice. Please select a valid option (1/2/3)." << std::endl;
    }

    return 0;
}
