#include "Machine.h"
#include <iostream>

Machine::Machine() : make("unknown"), model("unknown"), reg_number("") {
    std::cout << "Machine: default constructor\n";
}

Machine::Machine(const std::string& make_, const std::string& model_, const std::string& reg)
    : make(make_), model(model_), reg_number(reg) {
    std::cout << "Machine: parameter constructor\n";
}

Machine::Machine(const Machine& other)
    : make(other.make), model(other.model), reg_number(other.reg_number) {
    std::cout << "Machine: copy constructor\n";
}

Machine::~Machine() {
    std::cout << "Machine: destructor\n";
}

void Machine::setMake(const std::string& m) { make = m; }
std::string Machine::getMake() const { return make; }

void Machine::print() const {
    std::cout << "[Machine] " << make << " " << model << ", reg=" << reg_number << "\n";
}

void Machine::save(std::ofstream& out) const {
    // формат: MACHINE\n<make>\n<model>\n<reg>\n
    out << "MACHINE" << '\n';
    out << make << '\n';
    out << model << '\n';
    out << reg_number << '\n';
}
