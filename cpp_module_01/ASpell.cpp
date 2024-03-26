
#include "ASpell.hpp"

ASpell::ASpell()
{
}

ASpell::~ASpell()
{
}

ASpell::ASpell(std::string name, std::string effects):_name(name), _effects(effects)
{
}

ASpell::ASpell(ASpell const &obj)
{
    *this = obj;
}

ASpell & ASpell::operator=(ASpell const & obj)
{
    _name = obj._name;
    _effects = obj._effects;
    return *this;
}

std::string ASpell::getName() const
{
    return _name;
}
std::string ASpell::getEffects() const
{
    return _effects;
}
void ASpell::launch(ATarget const & target)
{
    target.getHitBySpell(*this);
}