/// @copyright gm 2021

#ifndef SUMMATOR_H
#define SUMMATOR_H

#include "core/reference.h"

class Serial : public Reference {
    GDCLASS(Serial, Reference);

    int count;

protected:
    static void _bind_methods();

public:
    void add(int p_value);
    void reset();
    int get_total() const;

    Serial();
};

#endif // SUMMATOR_H
