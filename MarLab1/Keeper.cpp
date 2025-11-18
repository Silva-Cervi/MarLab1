#include "Keeper.h"
#include "Furniture.h"
#include "Worker.h"
#include "Machine.h"
#include <iostream>
#include <sstream>

Keeper::Keeper() : items(nullptr), size(0), capacity(0) {
    resize(4);
    std::cout << "Keeper: default constructor\n";
}

void Keeper::resize(int newCap) {
    if (newCap <= capacity) return;
    Base** newItems = new Base * [newCap];
    for (int i = 0; i < size; ++i) newItems[i] = items[i];
    for (int i = size; i < newCap; ++i) newItems[i] = nullptr;
    delete[] items;
    items = newItems;
    capacity = newCap;
}

Keeper::Keeper(const Keeper& other) : items(nullptr), size(0), capacity(0) {
    resize(other.capacity);
    for (int i = 0; i < other.size; ++i) {
        items[i] = other.items[i]->clone();
    }
    size = other.size;
    std::cout << "Keeper: copy constructor\n";
}

Keeper& Keeper::operator=(const Keeper& other) {
    if (this == &other) return *this;
    clear();
    resize(other.capacity);
    for (int i = 0; i < other.size; ++i) items[i] = other.items[i]->clone();
    size = other.size;
    std::cout << "Keeper: assignment operator\n";
    return *this;
}

Keeper::~Keeper() {
    clear();
    delete[] items;
    std::cout << "Keeper: destructor\n";
}

void Keeper::add(Base* obj) {
    if (!obj) throw FactoryException("Attempt to add null object");
    if (size >= capacity) resize(capacity * 2);
    items[size++] = obj;
}

void Keeper::removeAt(int index) {
    if (index < 0 || index >= size) throw FactoryException("Index out of range");
    delete items[index];
    for (int i = index; i < size - 1; ++i) items[i] = items[i + 1];
    items[--size] = nullptr;
}

Base* Keeper::getAt(int index) const {
    if (index < 0 || index >= size) throw FactoryException("Index out of range");
    return items[index];
}

void Keeper::clear() {
    for (int i = 0; i < size; ++i) {
        delete items[i]; items[i] = nullptr;
    }
    size = 0;
}

void Keeper::saveToFile(const std::string& filename) const {
    std::ofstream out(filename.c_str());
    if (!out) throw FactoryException(std::string("Невозможно открыть файл для чтения: ") + filename);
    out << size << '\n';
    for (int i = 0; i < size; ++i) {
        items[i]->save(out);
    }
    out.close();
}

void Keeper::loadFromFile(const std::string& filename) {
    std::ifstream in(filename.c_str());
    if (!in) throw FactoryException(std::string("Cannot open file for reading: ") + filename);
    clear();
    int n = 0;
    in >> n;
    std::string dummy;
    std::getline(in, dummy); // consume endline
    resize(n > 4 ? n : 4);
    for (int i = 0; i < n; ++i) {
        std::string type;
        if (!std::getline(in, type)) throw FactoryException("Unexpected EOF while reading object type");
        if (type == "FURNITURE") {
            std::string f_type; std::getline(in, f_type);
            double h, w, d; in >> h >> w >> d; std::getline(in, dummy);
            std::string color; std::getline(in, color);
            std::string material; std::getline(in, material);
            double cost; in >> cost; std::getline(in, dummy);
            Furniture* f = new Furniture(f_type, h, w, d, color, material, cost);
            add(f);
        }
        else if (type == "WORKER") {
            std::string fio; std::getline(in, fio);
            std::string position; std::getline(in, position);
            double salary; in >> salary; std::getline(in, dummy);
            std::string address; std::getline(in, address);
            std::string phone; std::getline(in, phone);
            Worker* wkr = new Worker(fio, position, salary, address, phone);
            add(wkr);
        }
        else if (type == "MACHINE") {
            std::string make; std::getline(in, make);
            std::string model; std::getline(in, model);
            std::string reg; std::getline(in, reg);
            Machine* m = new Machine(make, model, reg);
            add(m);
        }
        else {
            throw FactoryException(std::string("Unknown object type in file: ") + type);
        }
    }
    in.close();
}
