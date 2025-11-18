#include "Machine.h"
#include <iostream>

Machine::Machine() : make("неизвестно"), model("неизвестно"), reg_number("") {
    std::cout << "Machine: конструктор по умолчанию\n";
}

Machine::Machine(const std::string& make_, const std::string& model_, const std::string& reg)
    : make(make_), model(model_), reg_number(reg) {
    std::cout << "Machine: параметрический конструктор\n";
}

Machine::Machine(const Machine& other)
    : make(other.make), model(other.model), reg_number(other.reg_number) {
    std::cout << "Machine: конструктор копирования\n";
}

Machine::~Machine() {
    std::cout << "Machine: деструктор\n";
}

void Machine::setMake(const std::string& m) { make = m; }
std::string Machine::getMake() const { return make; }

void Machine::print() const {
    std::cout << "[Машина] " << make << " " << model << ", гос.№=" << reg_number << "\n";
}

void Machine::save(std::ofstream& out) const {
    // формат: MACHINE\n<make>\n<model>\n<reg>\n
    out << "MACHINE" << '\n';
    out << make << '\n';
    out << model << '\n';
    out << reg_number << '\n';
}
