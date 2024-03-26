#include "SpellBook.hpp"

SpellBook::SpellBook()
{
}

SpellBook::~SpellBook()
{
    std::map<std::string, ASpell*>::iterator it_begin = _spellBook.begin();
    std::map<std::string, ASpell*>::iterator it_end = _spellBook.end();
    while (it_begin != it_end)
    {
        delete it_begin->second;
        it_begin++;
    }
    _spellBook.clear();
}

SpellBook::SpellBook(SpellBook const & obj)
{
    *this = obj;
}

SpellBook &SpellBook::operator=(SpellBook const & obj)
{
    _spellBook = obj._spellBook;
    return *this;
}

void SpellBook::learnSpell(ASpell* spell)
{
    if (spell)
    {
        _spellBook.insert(std::pair<std::string, ASpell*>(spell->getName(), spell->clone()));
    }
}
void SpellBook::forgetSpell(std::string const & spellName)
{
    std::map<std::string, ASpell*>::iterator it = _spellBook.find(spellName);
    if (it != _spellBook.end())
    {
        delete it->second;
        _spellBook.erase(spellName);
    }
}

ASpell* SpellBook::createSpell(std::string const & spellName)
{
    std::map<std::string, ASpell*>::iterator it = _spellBook.find(spellName);
    if (it != _spellBook.end())
    {
        return _spellBook[spellName];
    }
    return NULL;
}