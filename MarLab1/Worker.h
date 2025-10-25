#ifndef WORKER_H
#define WORKER_H

#include "Base.h"

class Worker : public Base {
    std::string fio;
    std::string position;
    double salary;
    std::string address;
    std::string phone;
public:
    Worker();
    Worker(const std::string& fio, const std::string& pos, double sal, const std::string& addr, const std::string& phone);
    Worker(const Worker& other);
    ~Worker();

    void setFIO(const std::string& s); std::string getFIO() const;

    void print() const override;
    void save(std::ofstream& out) const override;
    Base* clone() const override { return new Worker(*this); }
    std::string type() const override { return "WORKER"; }
};

#endif // WORKER_H
