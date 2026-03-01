#ifndef IMODIFIER_H
#define IMODIFIER_H

class IModifier {
public:
    virtual int apply(int baseScore) = 0;
    virtual ~IModifier() {}
};

#endif