#ifndef KEEPER_H
#define KEEPER_H

#include "Base.h"
#include "exceptions.h"
#include <fstream>
#include <string>

class Keeper {
    Base** items;
    int size;
    int capacity;
    void resize(int newCap);
public:
    Keeper();
    Keeper(const Keeper& other);
    Keeper& operator=(const Keeper& other);
    ~Keeper();

    void add(Base* obj); // владеет obj
    void removeAt(int index);
    int getSize() const { return size; }
    Base* getAt(int index) const;

    void clear();

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif // KEEPER_H
