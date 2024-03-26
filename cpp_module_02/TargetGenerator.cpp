#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{
}

TargetGenerator::~TargetGenerator()
{
    std::map<std::string, ATarget*>::iterator it_begin = _targetBook.begin();
    std::map<std::string, ATarget*>::iterator it_end = _targetBook.end();
    while (it_begin != it_end)
    {
        delete it_begin->second;
        it_begin++;
    }
    _targetBook.clear();
}

TargetGenerator::TargetGenerator(TargetGenerator const & obj)
{
    *this = obj;
}
TargetGenerator & TargetGenerator::operator=(TargetGenerator const & obj)
{
    _targetBook = obj._targetBook;
    return *this;
}
void TargetGenerator::learnTargetType(ATarget* target)
{
    if (target)
    {
        _targetBook.insert(std::pair<std::string, ATarget*>(target->getType(), target->clone()));
    }
}
void TargetGenerator::forgetTargetType(std::string const & targetType)
{
    std::map<std::string, ATarget*>::iterator it = _targetBook.find(targetType);
    if (it != _targetBook.end())
    {
        delete it->second;
        _targetBook.erase(targetType);
    }
}
ATarget* TargetGenerator::createTarget(std::string const & targetType)
{
    std::map<std::string, ATarget*>::iterator it = _targetBook.find(targetType);
    if (it != _targetBook.end())
    {
        return _targetBook[targetType];
    }
    return NULL;
}