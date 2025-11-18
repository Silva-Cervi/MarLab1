#include "Furniture.h"
#include <iostream>

Furniture::Furniture() : f_type("неизвестно"), height(0), width(0), depth(0), color("нет"), material("нет"), cost(0) {
    std::cout << "Furniture: конструктор по умолчанию\n";
}

Furniture::Furniture(const std::string& t, double h, double w, double d, const std::string& c, const std::string& m, double cost)
    : f_type(t), height(h), width(w), depth(d), color(c), material(m), cost(cost) {
    std::cout << "Furniture: параметрический конструктор\n";
}

Furniture::Furniture(const Furniture& other)
    : f_type(other.f_type), height(other.height), width(other.width), depth(other.depth), color(other.color), material(other.material), cost(other.cost) {
    std::cout << "Furniture: конструктор копирования\n";
}

Furniture::~Furniture() {
    std::cout << "Furniture: деструктор\n";
}

void Furniture::setType(const std::string& t) { f_type = t; }
std::string Furniture::getType() const { return f_type; }

void Furniture::print() const {
    std::cout << "[Мебель] тип=" << f_type
        << ", ГxШxГл=" << height << "x" << width << "x" << depth
        << ", цвет=" << color << ", материал=" << material
        << ", стоимость=" << cost << "\n";
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
