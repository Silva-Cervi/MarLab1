#ifndef FURNITURE_H
#define FURNITURE_H

#include "Base.h"

class Furniture : public Base {
    std::string f_type; // тип мебели
    double height, width, depth;
    std::string color;
    std::string material;
    double cost;
public:
    Furniture();
    Furniture(const std::string& t, double h, double w, double d, const std::string& c, const std::string& m, double cost);
    Furniture(const Furniture& other);
    ~Furniture();

    // set/get
    void setType(const std::string& t);
    std::string getType() const;

    void print() const override;
    void save(std::ofstream& out) const override;
    Base* clone() const override { return new Furniture(*this); }
    std::string type() const override { return "FURNITURE"; }
};

#endif // FURNITURE_H
