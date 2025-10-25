#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <fstream>
#include <string>

class Base {
public:
    Base();
    Base(const Base&);
    virtual ~Base();

    virtual void print() const = 0;
    virtual void save(std::ofstream& out) const = 0;
    // при загрузке статический фабричный метод в Keeper создаёт объект
    virtual Base* clone() const = 0;
    virtual std::string type() const = 0;
};

#endif // BASE_H
