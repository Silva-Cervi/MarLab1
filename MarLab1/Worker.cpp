#include "Worker.h"
#include <iostream>

Worker::Worker() : fio("unknown"), position("none"), salary(0), address(""), phone("") {
    std::cout << "Worker: default constructor\n";
}

Worker::Worker(const std::string& fio_, const std::string& pos, double sal, const std::string& addr, const std::string& phone_)
    : fio(fio_), position(pos), salary(sal), address(addr), phone(phone_) {
    std::cout << "Worker: parameter constructor\n";
}

Worker::Worker(const Worker& other)
    : fio(other.fio), position(other.position), salary(other.salary), address(other.address), phone(other.phone) {
    std::cout << "Worker: copy constructor\n";
}

Worker::~Worker() {
    std::cout << "Worker: destructor\n";
}

void Worker::setFIO(const std::string& s) { fio = s; }
std::string Worker::getFIO() const { return fio; }

void Worker::print() const {
    std::cout << "[Worker] " << fio << ", position=" << position << ", salary=" << salary
        << ", address=" << address << ", phone=" << phone << "\n";
}

void Worker::save(std::ofstream& out) const {
    // формат: WORKER\n<fio>\n<position>\n<salary>\n<address>\n<phone>\n
    out << "WORKER" << '\n';
    out << fio << '\n';
    out << position << '\n';
    out << salary << '\n';
    out << address << '\n';
    out << phone << '\n';
}
