#pragma once
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
protected:
    std::string _type;
public:
    ATarget();
    ATarget(std::string type);
    virtual ~ATarget();
    ATarget(ATarget const & obj);
    ATarget &operator=(ATarget const & obj);
    std::string const & getType() const;
    virtual ATarget* clone() const = 0;
    void getHitBySpell(ASpell const & spell) const;
};
