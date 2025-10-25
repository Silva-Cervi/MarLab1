#ifndef MACHINE_H
#define MACHINE_H

#include "Base.h"

class Machine : public Base {
    std::string make;
    std::string model;
    std::string reg_number;
public:
    Machine();
    Machine(const std::string& make, const std::string& model, const std::string& reg);
    Machine(const Machine& other);
    ~Machine();

    void setMake(const std::string& m); std::string getMake() const;

    void print() const override;
    void save(std::ofstream& out) const override;
    Base* clone() const override { return new Machine(*this); }
    std::string type() const override { return "MACHINE"; }
};

#endif // MACHINE_H
