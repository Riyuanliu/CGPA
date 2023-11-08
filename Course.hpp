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
    int numberGrade;
    std::vector<Assignment> assignments;
public:
    Course(){
        name="";
        letterGrade="F";
        credit=0;
        assignments={};
        numberGrade=0;
    }
    Course(const std::string& name, const std::string& letterGrade="F", int credit=0)
        : name(name), letterGrade(letterGrade), credit(credit) {}
    void setAssignment(std::vector<Assignment> list){
        assignments=list;
        setlettergrade();
    }
    void addAssignment(const Assignment& assignment) {
        assignments.push_back(assignment);
        setlettergrade();
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
    int getNumbGrade(){
        return numberGrade;
    }
    void setNumbGrade(int grade){
        numberGrade=grade;
    }
    void setlettergrade(){
        // Convert the numeric grade to a letter grade
        int numericGrade=calculateAverageGrade();
        setNumbGrade(numericGrade);
        if (numericGrade >= 90) {
            letterGrade = 'A';
        } else if (numericGrade >= 80) {
            letterGrade = 'B';
        } else if (numericGrade >= 70) {
            letterGrade = 'C';
        } else if (numericGrade >= 60) {
            letterGrade = 'D';
        } else {
            letterGrade = 'F';
        }
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
    void printallassignment(){
        std::cout<<getName()<<" : "<<calculateAverageGrade()<<"____"<<getLetterGrade()<<" "<< std::endl;
        for(int i = 0; i<assignments.size();i++){
            std::cout<<"    "<<assignments[i].getName()<<" : "<<assignments[i].getGrade()<<std::endl;
        }
    }
};

#endif /* Course_hpp */
