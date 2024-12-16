#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

class Person {
private:
    std::string name;
    int height;
public:
    Person(std::string personName, int personHeight) : name(personName), height(personHeight) {}

    std::string toString() const {
        return name + ", рост: " + std::to_string(height);
    }
};

void first() {
    Person cleopatra("Клеопатра", 152);
    Person pushkin("Пушкин", 167);
    Person vladimir("Владимир", 189);

    std::cout << cleopatra.toString() << std::endl;
    std::cout << pushkin.toString() << std::endl;
    std::cout << vladimir.toString() << std::endl;
}

class FullName {
private:
    std::string lastName;
    std::string firstName;
    std::string patronymic;
public:
    // Конструктор для личного имени
    FullName(std::string first) : firstName(first), lastName(""), patronymic("") {}

    // Конструктор для личного имени и фамилии
    FullName(std::string first, std::string last) : firstName(first), lastName(last), patronymic("") {}

    // Конструктор для полного имени
    FullName(std::string first, std::string last, std::string patronym) 
        : firstName(first), lastName(last), patronymic(patronym) {}

    std::string toString() const {
        std::string result = firstName;
        if (!lastName.empty()) {
            result += " " + lastName;
        }
        if (!patronymic.empty()) {
            result += " " + patronymic;
        }
        return result;
    }
};

void second() {
    FullName name1("Клеопатра"); // Только личное имя
    FullName name2("Александр", "Пушкин", "Сергеевич"); // Личное имя, фамилия и отчество
    FullName name3("Владимир", "Маяковский"); // Личное имя и фамилия

    std::cout << name1.toString() << std::endl;
    std::cout << name2.toString() << std::endl;
    std::cout << name3.toString() << std::endl;
}
void third() {
    FullName name1("Клеопатра"); // Только личное имя
    FullName name2("Александр", "Пушкин", "Сергеевич"); // Личное имя, фамилия и отчество
    FullName name3("Владимир", "Маяковский"); // Личное имя и фамилия
    FullName name4("Христофор", "Бонифатьевич"); // Личное имя и фамилия (отчество не задается)

    std::cout << name1.toString() << std::endl;
    std::cout << name2.toString() << std::endl;
    std::cout << name3.toString() << std::endl;
    std::cout << name4.toString() << std::endl;
}

class Department {
private:
    std::string name;
    std::string chief;
    std::vector<std::string> employees;
public:
    Department(std::string deptName, std::string deptChief) : name(deptName), chief(deptChief) {}

    void addEmployee(std::string empName) {
        employees.push_back(empName);
    }

    std::string getName() const {
        return name;
    }

    std::string getChief() const {
        return chief;
    }

    void listEmployees() const {
        std::cout << "Сотрудники отдела " << name << ": ";
        for (const auto& emp : employees) {
            std::cout << emp << " ";
        }
        std::cout << std::endl;
    }
};

class Employee {
private:
    std::string name;
    Department* department;
public:
    Employee(std::string empName, Department* dept) : name(empName), department(dept) {
        department->addEmployee(empName);
    }

    std::string toString() const {
        return name + " работает в отделе " + department->getName() + 
               ", начальник которого " + department->getChief();
    }
};

void fourth() {
    Department itDepartment("IT", "Козлов");
    Employee employee1("Петров", &itDepartment);
    Employee employee2("Сидоров", &itDepartment);
    Employee employee3("Козлов", &itDepartment);

    std::cout << employee1.toString() << std::endl;
    std::cout << employee2.toString() << std::endl;
    std::cout << employee3.toString() << std::endl;
}
void fifth() {
    Department itDepartment("IT", "Козлов");
    Employee employee1("Петров", &itDepartment);
    Employee employee2("Сидоров", &itDepartment);
    Employee employee3("Козлов", &itDepartment);

    std::cout << employee1.toString() << std::endl;
    std::cout << employee2.toString() << std::endl;
    std::cout << employee3.toString() << std::endl;

    itDepartment.listEmployees();
}

class Gun {
private:
    int bullets;
public:
    Gun(int initialBullets = 5) : bullets(initialBullets) {}

    void shoot() {
        if (bullets > 0) {
            std::cout << "Бах!" << std::endl;
            bullets--;
        } else {
            std::cout << "Клац!" << std::endl;
        }
    }
};

void sixth() {
    Gun gun(3);
    for (int i = 0; i < 5; i++) {
        gun.shoot();
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice;

    do {
        std::cout << "\nВыберите действие:\n";
        std::cout << "1. first\n";
        std::cout << "2. second\n";
        std::cout << "3. third\n"; 
        std::cout << "4. fourth\n";
        std::cout << "5. fifth\n";
        std::cout << "6. sixth\n";
        std::cout << "0. Выход\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                first();
                break;
            case 2:
                second();
                break;
            case 3:
                third(); 
                break;
            case 4:
                fourth();
                break;
            case 5:
                fifth();
                break;
            case 6:
                sixth();
                break;
            case 0:
                std::cout << "Выход из программы." << std::endl;
                break;
            default:
                std::cout << "Неверный выбор, попробуйте снова." << std::endl;
                break;
        }
    } while (choice != 0);

    return 0;
}
