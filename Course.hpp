//
//  Course.hpp
//  CGPA
//
//  Created by Riyuan Liu on 9/19/23.
//

#ifndef Course_hpp
#define Course_hpp
#include "Assignment.hpp"
#include <vector>
class Course {
private:
    std::string name;
    std::string letterGrade;
    int credit;
    std::vector<Assignment> assignments;
public:
    Course(const std::string& name, const std::string& letterGrade, int credit)
        : name(name), letterGrade(letterGrade), credit(credit) {}

    void addAssignment(const Assignment& assignment) {
        assignments.push_back(assignment);
    }

    std::string getName() const {
        return name;
    }

    std::string getLetterGrade() const {
        return letterGrade;
    }

    int getCredit() const {
        return credit;
    }

    double calculateAverageGrade() const {
        if (assignments.empty()) {
            return 0.0;
        }

        double weightedSum = 0.0;
        double totalWeight = 0.0;

        for (const Assignment& assignment : assignments) {
            weightedSum += (assignment.getGrade() * assignment.getWeight());
            totalWeight += assignment.getWeight();
        }

        return weightedSum / totalWeight;
    }
};

#endif /* Course_hpp */
