#include <iostream>
#include <limits>
#include "Keeper.h"
#include "Furniture.h"
#include "Worker.h"
#include "Machine.h"
#include "exceptions.h"

void printMenu() {
    std::cout << "\n--- Меню ---\n";
    std::cout << "1. Добавить мебель\n";
    std::cout << "2. Добавить работника\n";
    std::cout << "3. Добавить машину\n";
    std::cout << "4. Показать все\n";
    std::cout << "5. Удалить по индексу\n";
    std::cout << "6. Сохранить в файл\n";
    std::cout << "7. Загрузить из файла\n";
    std::cout << "0. Выход\n";
}

int main() {
    setlocale(LC_ALL, "Russian");
    Keeper k;
    int choice = -1;
    while (choice != 0) {
        try {
            printMenu();
            std::cout << "Выберите пункт: ";
            if (!(std::cin >> choice)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Неверный ввод\n";
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (choice == 1) {
                std::string type, color, material;
                double h, w, d, cost;
                std::cout << "Тип мебели: "; std::getline(std::cin, type);
                std::cout << "Высота: "; std::cin >> h; std::cin.ignore();
                std::cout << "Ширина: "; std::cin >> w; std::cin.ignore();
                std::cout << "Глубина: "; std::cin >> d; std::cin.ignore();
                std::cout << "Цвет: "; std::getline(std::cin, color);
                std::cout << "Материал: "; std::getline(std::cin, material);
                std::cout << "Стоимость: "; std::cin >> cost; std::cin.ignore();
                Furniture* f = new Furniture(type, h, w, d, color, material, cost);
                k.add(f);
            }
            else if (choice == 2) {
                std::string fio, pos, addr, phone; double sal;
                std::cout << "ФИО: "; std::getline(std::cin, fio);
                std::cout << "Должность: "; std::getline(std::cin, pos);
                std::cout << "Зарплата: "; std::cin >> sal; std::cin.ignore();
                std::cout << "Адрес: "; std::getline(std::cin, addr);
                std::cout << "Телефон: "; std::getline(std::cin, phone);
                Worker* w = new Worker(fio, pos, sal, addr, phone);
                k.add(w);
            }
            else if (choice == 3) {
                std::string make, model, reg;
                std::cout << "Марка: "; std::getline(std::cin, make);
                std::cout << "Модель: "; std::getline(std::cin, model);
                std::cout << "Гос.номер: "; std::getline(std::cin, reg);
                Machine* m = new Machine(make, model, reg);
                k.add(m);
            }
            else if (choice == 4) {
                int n = k.getSize();
                std::cout << "Всего объектов: " << n << "\n";
                for (int i = 0; i < n; ++i) {
                    std::cout << i << ": ";
                    k.getAt(i)->print();
                }
            }
            else if (choice == 5) {
                int idx; std::cout << "Индекс для удаления: "; std::cin >> idx; std::cin.ignore();
                k.removeAt(idx);
                std::cout << "Удалено\n";
            }
            else if (choice == 6) {
                std::string fname; std::cout << "Имя файла: "; std::getline(std::cin, fname);
                k.saveToFile(fname);
                std::cout << "Сохранено\n";
            }
            else if (choice == 7) {
                std::string fname; std::cout << "Имя файла: "; std::getline(std::cin, fname);
                k.loadFromFile(fname);
                std::cout << "Загружено\n";
            }
            else if (choice == 0) {
                std::cout << "Выход...\n";
            }
            else {
                std::cout << "Неизвестный пункт\n";
            }
        }
        catch (const FactoryException& ex) {
            std::cout << "Ошибка: " << ex.what() << "\n";
        }
        catch (const std::exception& ex) {
            std::cout << "std::exception: " << ex.what() << "\n";
        }
    }
    return 0;
}
