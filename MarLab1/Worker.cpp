#include "Worker.h"
#include <iostream>

Worker::Worker() : fio("неизвестно"), position("нет"), salary(0), address(""), phone("") {
    std::cout << "Worker: конструктор по умолчанию\n";
}

Worker::Worker(const std::string& fio_, const std::string& pos, double sal, const std::string& addr, const std::string& phone_)
    : fio(fio_), position(pos), salary(sal), address(addr), phone(phone_) {
    std::cout << "Worker: параметрический конструктор\n";
}

Worker::Worker(const Worker& other)
    : fio(other.fio), position(other.position), salary(other.salary), address(other.address), phone(other.phone) {
    std::cout << "Worker: конструктор копирования\n";
}

Worker::~Worker() {
    std::cout << "Worker: деструктор\n";
}

void Worker::setFIO(const std::string& s) { fio = s; }
std::string Worker::getFIO() const { return fio; }

void Worker::print() const {
    std::cout << "[Работник] " << fio << ", должность=" << position << ", зарплата=" << salary
        << ", адрес=" << address << ", телефон=" << phone << "\n";
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
