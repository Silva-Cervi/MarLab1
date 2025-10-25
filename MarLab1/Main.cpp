#include <iostream>
#include <limits>
#include "Keeper.h"
#include "Furniture.h"
#include "Worker.h"
#include "Machine.h"
#include "exceptions.h"

void printMenu() {
    std::cout << "\n--- ���� ---\n";
    std::cout << "1. �������� ������\n";
    std::cout << "2. �������� ���������\n";
    std::cout << "3. �������� ������\n";
    std::cout << "4. �������� ���\n";
    std::cout << "5. ������� �� �������\n";
    std::cout << "6. ��������� � ����\n";
    std::cout << "7. ��������� �� �����\n";
    std::cout << "0. �����\n";
}

int main() {
    setlocale(LC_ALL, "Russian");
    Keeper k;
    int choice = -1;
    while (choice != 0) {
        try {
            printMenu();
            std::cout << "�������� �����: ";
            if (!(std::cin >> choice)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "�������� ����\n";
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (choice == 1) {
                std::string type, color, material;
                double h, w, d, cost;
                std::cout << "��� ������: "; std::getline(std::cin, type);
                std::cout << "������: "; std::cin >> h; std::cin.ignore();
                std::cout << "������: "; std::cin >> w; std::cin.ignore();
                std::cout << "�������: "; std::cin >> d; std::cin.ignore();
                std::cout << "����: "; std::getline(std::cin, color);
                std::cout << "��������: "; std::getline(std::cin, material);
                std::cout << "���������: "; std::cin >> cost; std::cin.ignore();
                Furniture* f = new Furniture(type, h, w, d, color, material, cost);
                k.add(f);
            }
            else if (choice == 2) {
                std::string fio, pos, addr, phone; double sal;
                std::cout << "���: "; std::getline(std::cin, fio);
                std::cout << "���������: "; std::getline(std::cin, pos);
                std::cout << "��������: "; std::cin >> sal; std::cin.ignore();
                std::cout << "�����: "; std::getline(std::cin, addr);
                std::cout << "�������: "; std::getline(std::cin, phone);
                Worker* w = new Worker(fio, pos, sal, addr, phone);
                k.add(w);
            }
            else if (choice == 3) {
                std::string make, model, reg;
                std::cout << "�����: "; std::getline(std::cin, make);
                std::cout << "������: "; std::getline(std::cin, model);
                std::cout << "���.�����: "; std::getline(std::cin, reg);
                Machine* m = new Machine(make, model, reg);
                k.add(m);
            }
            else if (choice == 4) {
                int n = k.getSize();
                std::cout << "����� ��������: " << n << "\n";
                for (int i = 0; i < n; ++i) {
                    std::cout << i << ": ";
                    k.getAt(i)->print();
                }
            }
            else if (choice == 5) {
                int idx; std::cout << "������ ��� ��������: "; std::cin >> idx; std::cin.ignore();
                k.removeAt(idx);
                std::cout << "�������\n";
            }
            else if (choice == 6) {
                std::string fname; std::cout << "��� �����: "; std::getline(std::cin, fname);
                k.saveToFile(fname);
                std::cout << "���������\n";
            }
            else if (choice == 7) {
                std::string fname; std::cout << "��� �����: "; std::getline(std::cin, fname);
                k.loadFromFile(fname);
                std::cout << "���������\n";
            }
            else if (choice == 0) {
                std::cout << "�����...\n";
            }
            else {
                std::cout << "����������� �����\n";
            }
        }
        catch (const FactoryException& ex) {
            std::cout << "������: " << ex.what() << "\n";
        }
        catch (const std::exception& ex) {
            std::cout << "std::exception: " << ex.what() << "\n";
        }
    }
    return 0;
}
