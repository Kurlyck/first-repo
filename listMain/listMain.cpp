#include <iostream>
#include <string>

struct Ticket {
    int row;
    int seat;
    std::string lastName;
};

const int MAX_TICKETS = 100;
Ticket reservedTickets[MAX_TICKETS];
Ticket purchasedTickets[MAX_TICKETS];
int numReservedTickets = 0;
int numPurchasedTickets = 0;

void reserveTicket(int row, int seat, const std::string& lastName) {
    if (numReservedTickets < MAX_TICKETS) {
        reservedTickets[numReservedTickets] = { row, seat, lastName };
        numReservedTickets++;
        std::cout << "Билет успешно забронирован" << std::endl;
    }
    else {
        std::cout << "Достигнуто максимальное количество забронированных билетов" << std::endl;
    }
}

void purchaseTicket(int row, int seat) {
    bool found = false;
    for (int i = 0; i < numReservedTickets; ++i) {
        if (reservedTickets[i].row == row && reservedTickets[i].seat == seat) {
            purchasedTickets[numPurchasedTickets] = reservedTickets[i];
            numPurchasedTickets++;

            for (int j = i; j < numReservedTickets - 1; ++j) {
                reservedTickets[j] = reservedTickets[j + 1];
            }
            numReservedTickets--;

            found = true;
            break;
        }
    }

    if (found) {
        std::cout << "Билет успешно куплен" << std::endl;
    }
    else {
        std::cout << "Билет не найден в списке забронированных" << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    while (true) {
        std::cout << "1. Забронировать билет" << std::endl;
        std::cout << "2. Купить билет" << std::endl;
        std::cout << "3. Выйти" << std::endl;

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            int row, seat;
            std::string lastName;
            std::cout << "Введите номер ряда: ";
            std::cin >> row;
            std::cout << "Введите номер места: ";
            std::cin >> seat;
            std::cout << "Введите фамилию бронирующего: ";
            std::cin >> lastName;

            reserveTicket(row, seat, lastName);
        }
        else if (choice == 2) {
            int row, seat;
            std::cout << "Введите номер ряда: ";
            std::cin >> row;
            std::cout << "Введите номер места: ";
            std::cin >> seat;

            purchaseTicket(row, seat);
        }
        else if (choice == 3) {
            break;
        }
        else {
            std::cout << "Некорректный выбор. Повторите попытку." << std::endl;
        }
    }

    std::cout << "Список забронированных билетов:" << std::endl;
    for (int i = 0; i < numReservedTickets; ++i) {
        std::cout << "Ряд " << reservedTickets[i].row << ", Место " << reservedTickets[i].seat << ", Фамилия: " << reservedTickets[i].lastName << std::endl;
    }

    std::cout << "Список купленных билетов:" << std::endl;
    for (int i = 0; i < numPurchasedTickets; ++i) {
        std::cout << "Ряд " << purchasedTickets[i].row << ", Место " << purchasedTickets[i].seat << std::endl;
    }

    return 0;
}
