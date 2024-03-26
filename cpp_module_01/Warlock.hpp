#pragma once
#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class ASpell;
class ATarget;

class Warlock
{
private:
    std::string _name;
    std::string _title;
    std::map<std::string, ASpell*> _spellBook;
    Warlock();
    Warlock(Warlock const & obj);
    Warlock &operator=(Warlock const & obj);
public:
    Warlock(std::string name, std::string title);
    ~Warlock();
    std::string getName() const;
    std::string getTitle() const;
    void setTitle(std::string const & title);
    void introduce() const;
    void learnSpell(ASpell *spell);
    void forgetSpell(std::string spellName);
    void launchSpell(std::string spellName, ATarget & target);
};

