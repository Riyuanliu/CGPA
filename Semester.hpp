//
//  Semester.hpp
//  CGPA
//
//  Created by Riyuan Liu on 9/19/23.
//

#ifndef Semester_hpp
#define Semester_hpp

#include <stdio.h>
#include "Course.hpp"
class Semester {
public:
    Semester(const std::string& name)
        : name(name) {}

    void addCourse(const Course& course) {
        courses.push_back(course);
    }

    std::string getName() const {
        return name;
    }

    double calculateGPA() const {
        if (courses.empty()) {
            return 0.0;
        }

        double totalGradePoints = 0.0;
        int totalCredits = 0;

        for (const Course& course : courses) {
            totalGradePoints += course.calculateAverageGrade() * course.getCredit();
            totalCredits += course.getCredit();
        }

        return totalGradePoints / totalCredits;
    }
    void printallsemester(){
        std::cout<<getName()<<std::endl;
        for(int i =0;i<courses.size();i++){
            courses[i].printallassignment();
        }
    }

private:
    std::string name;
    std::vector<Course> courses;
};
#endif /* Semester_hpp */
