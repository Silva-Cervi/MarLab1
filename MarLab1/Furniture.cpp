#include "Furniture.h"
#include <iostream>

Furniture::Furniture() : f_type("unknown"), height(0), width(0), depth(0), color("none"), material("none"), cost(0) {
    std::cout << "Furniture: default constructor\n";
}

Furniture::Furniture(const std::string& t, double h, double w, double d, const std::string& c, const std::string& m, double cost)
    : f_type(t), height(h), width(w), depth(d), color(c), material(m), cost(cost) {
    std::cout << "Furniture: parameter constructor\n";
}

Furniture::Furniture(const Furniture& other)
    : f_type(other.f_type), height(other.height), width(other.width), depth(other.depth), color(other.color), material(other.material), cost(other.cost) {
    std::cout << "Furniture: copy constructor\n";
}

Furniture::~Furniture() {
    std::cout << "Furniture: destructor\n";
}

void Furniture::setType(const std::string& t) { f_type = t; }
std::string Furniture::getType() const { return f_type; }

void Furniture::print() const {
    std::cout << "[Furniture] type=" << f_type
        << ", HxWxD=" << height << "x" << width << "x" << depth
        << ", color=" << color << ", material=" << material
        << ", cost=" << cost << "\n";
}

void Furniture::save(std::ofstream& out) const {
    // формат: FURNITURE\n<type>\n<height> <width> <depth>\n<color>\n<material>\n<cost>\n
    out << "FURNITURE" << '\n';
    out << f_type << '\n';
    out << height << ' ' << width << ' ' << depth << '\n';
    out << color << '\n';
    out << material << '\n';
    out << cost << '\n';
}
