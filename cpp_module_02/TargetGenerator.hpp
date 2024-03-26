#pragma once
#include <iostream>
#include "ATarget.hpp"
#include <map>

class TargetGenerator
{
private:
    std::map<std::string, ATarget*> _targetBook;
public:
    TargetGenerator();
    ~TargetGenerator();
    TargetGenerator(TargetGenerator const & obj);
    TargetGenerator &operator=(TargetGenerator const & obj);
    void learnTargetType(ATarget* target);
    void forgetTargetType(std::string const & targetType);
    ATarget* createTarget(std::string const & targetType);
};

