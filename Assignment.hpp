//
//  Assignment.hpp
//  CGPA
//
//  Created by Riyuan Liu on 9/20/23.
//

#ifndef Assignment_hpp
#define Assignment_hpp
#include <stdio.h>
#include <iostream>

class Assignment {
public:
    Assignment(const std::string& name, double grade, double weight)
        : name(name), grade(grade), weight(weight) {}

    std::string getName() const {
        return name;
    }

    double getGrade() const {
        return grade;
    }

    double getWeight() const {
        return weight;
    }

private:
    std::string name;
    double grade;
    double weight;
};


#endif /* Assignment_hpp */
