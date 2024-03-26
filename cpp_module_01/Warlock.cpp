#include "Warlock.hpp"
Warlock::Warlock(){
}

Warlock::Warlock(std::string name, std::string title):_name(name), _title(title)
{
    std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout << _name << ": My job here is done!" << std::endl;
    std::map<std::string, ASpell*>::iterator it_beg = _spellBook.begin();
    std::map<std::string, ASpell*>::iterator it_end = _spellBook.end();
    while (it_beg != it_end)
    {
        delete it_beg->second;
        it_beg++;
    }
    _spellBook.clear();
}

Warlock::Warlock(Warlock const & obj)
{
    *this = obj;
}
Warlock &Warlock::operator=(Warlock const & obj)
{
    _name = obj._name;
    _title = obj._title;
    return *this;
}
std::string Warlock::getName() const
{
    return _name;
}
std::string Warlock::getTitle() const
{
    return _title;
}
void Warlock::setTitle(std::string const & title)
{
    _title = title;
}
void Warlock::introduce() const
{
    std::cout << _name << ": I am "<< _name << ", " << _title<< "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell)
{
    if (spell)
    {
        _spellBook.insert(std::pair<std::string, ASpell*>(spell->getName(), spell->clone()));
    }
}
void Warlock::forgetSpell(std::string spellName)
{
    std::map<std::string, ASpell*>::iterator it = _spellBook.find(spellName);
    if (it != _spellBook.end())
    {
        delete it->second;
        _spellBook.erase(spellName);
    }
}
void Warlock::launchSpell(std::string spellName, ATarget & target)
{
    std::map<std::string, ASpell*>::iterator it = _spellBook.find(spellName);
    if (it != _spellBook.end())
    {
        _spellBook[spellName]->launch(target);
    }
}