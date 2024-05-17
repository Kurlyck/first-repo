#include <iostream>
#include <string>

struct Ticket {
    int row;
    int seat;
    std::string lastName;
    Ticket* prev;
    Ticket* next;
};

Ticket* findTicket(int row, int seat, Ticket* head) {
    setlocale(LC_ALL, "Russian");

    

    Ticket* current = head;
    while (current != nullptr) {
        if (current->row == row && current->seat == seat) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

    void addTicket(Ticket** head, Ticket** tail, int& length, int row, int seat, std::string name) {
        setlocale(LC_ALL, "Russian");

        if (findTicket(row, seat, *head)) {
            std::cout << "Такая бронь уже существует. " << std::endl;
            return;
        }

        Ticket* newTicket = new Ticket;
        newTicket->row = row;
        newTicket->seat = seat;
        newTicket->lastName = name;
        if (*head != nullptr && *tail != nullptr) {
            newTicket->prev = *tail;
            newTicket->prev->next = newTicket;
            newTicket->next = nullptr;
            *tail = newTicket;
            length++;
            std::cout << "Бронь успешно добавлена. " << std::endl;
            return;
        }
        else {
            newTicket->next = nullptr;
            newTicket->prev = nullptr;
            *head = newTicket;
            *tail = newTicket;
            length++;
            std::cout << "Бронь успешно добавлена. " << std::endl;
            return;
        }
        std::cout << "Произошла ошибка, попробуйте снова " << std::endl;
        return;
    }

    void deleteTicket(Ticket** head, Ticket** tail, int& length) {
        setlocale(LC_ALL, "Russian");

        if (*head == nullptr && *tail == nullptr) {
            std::cout << "Список пуст. Отменять нечего. " << std::endl;
            return;
        }

        int row;
        int seat;
        std::cout << "Выберите ряд: ";
        std::cin >> row;

        std::cout << "Выберите место: ";
        std::cin >> seat;

        Ticket* current = *head;
        while (current != nullptr) {
            if (current->row == row && current->seat == seat) {
                if (current->prev == nullptr && current->next != nullptr) {
                    current->next->prev = nullptr;
                    *head = current->next;
                    length--;
                    std::cout << "Бронь успешно снята. " << std::endl;
                    return;
                    /*if (head != nullptr) {
                        head->prev = nullptr;
                    }*/
                }
                else if (current->prev != nullptr && current->next == nullptr) {
                    current->prev->next = nullptr;
                    *tail = current->prev;
                    length--;
                    std::cout << "Бронь успешно снята. " << std::endl;
                    return;
                }
                else if (current->prev == nullptr && current->next == nullptr) {
                    *head = nullptr;
                    *tail = nullptr;
                    length--;
                    std::cout << "Бронь успешно снята. " << std::endl;
                    return;
                }
                else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    length--;
                    std::cout << "Бронь успешно снята. " << std::endl;
                    return;
                }
                return;
            }
            current = current->next;
        }
        std::cout << "Такой брони не существует. " << std::endl;
        return;
    }

    void printHeadTickets(Ticket* head) {
        setlocale(LC_ALL, "Russian");

        if (head == nullptr) {
            std::cout << "Список пуст. Выводить нечего. " << std::endl;
            return;
        }

        Ticket* current = head;
        while (current != nullptr) {
            std::cout << "Row: " << current->row << ", Seat: " << current->seat << ", Last Name: " << current->lastName << std::endl;
            current = current->next;
        }
        return;
    }

    void printTailTickets(Ticket* tail) {
        setlocale(LC_ALL, "Russian");

        if (tail == nullptr) {
            std::cout << "Список пуст. Выводить нечего. " << std::endl;
            return;
        }

        Ticket* current = tail;
        while (current != nullptr) {
            std::cout << "Row: " << current->row << ", Seat: " << current->seat << ", Last Name: " << current->lastName << std::endl;
            current = current->prev;
        }
        return;
    }


int main() {
    setlocale(LC_ALL, "Russian");

    Ticket* head = nullptr;
    Ticket* tail = nullptr;
    Ticket* foundTicket;
    int length = 0;
    int choice;
    int row1;
    int seat1;
    std::string name1;
    do {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Забронировать билет" << std::endl;
        std::cout << "2. Отменить бронь" << std::endl;
        std::cout << "3. Найти бронь" << std::endl;
        std::cout << "4. Вывести кол-во забронированных билетов" << std::endl;
        std::cout << "5. Вывести список брони с начала списка" << std::endl;
        std::cout << "6. Вывести список брони с конца списка" << std::endl;
        std::cout << "7. Выйти" << std::endl;
        std::cout << "Введите свой выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1:

            std::cout << "Выберите ряд: ";
            std::cin >> row1;

            std::cout << "Выберите место: ";
            std::cin >> seat1;

            std::cout << "Введите Имя/Фамилию: ";
            std::cin >> name1;

            addTicket(&head, &tail, length, row1, seat1, name1);
            break;
        case 2:
            deleteTicket(&head, &tail, length);
            break;
        case 3:
            std::cout << "Выберите ряд: ";
            std::cin >> row1;

            std::cout << "Выберите место: ";
            std::cin >> seat1;

            if (head == nullptr) {
                std::cout << "Список пустой. Искать нечего. ";
                break;
            }

            foundTicket = findTicket(row1, seat1, head);
            if (foundTicket != nullptr) {
                std::cout << "Билет найден: Ряд " << foundTicket->row << ", Место " << foundTicket->seat << ", Имя/Фамилия: " << foundTicket->lastName << std::endl;
                break;
            }
            else {
                std::cout << "Билет не найден" << std::endl;
                break;
            }
        case 4:
            std::cout << "Количество забронированных билетов: ";
            std::cout << length << std::endl;
            break;
        case 5:
            printHeadTickets(head);
            break;
        case 6:
            printTailTickets(tail);
            break;
        case 7:
            std::cout << "Выход с меню." << std::endl;
            break;
        default:
            std::cout << "Неккоретный выбор, попробуйте снова" << std::endl;
        }
    } while (choice != 7);

    return 0;
}
