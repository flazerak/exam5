
#include "ATarget.hpp"

ATarget::ATarget()
{
}

ATarget::~ATarget()
{
}

ATarget::ATarget(std::string type): _type(type)
{
}

ATarget::ATarget(ATarget const & obj)
{
    *this = obj;
}
ATarget & ATarget::operator=(ATarget const & obj)
{
    _type = obj._type ;
    return *this;
}

std::string const & ATarget::getType() const
{
    return _type;
}

void ATarget::getHitBySpell(ASpell const & spell) const
{
    std::cout << _type << " has been " << spell.getEffects()<< "!" << std::endl;
}
