#include <iostream>
#include <string>

const int MAX_SEATS = 100;

struct ResTicket {
    int row;
    int seat;
    std::string name;
};

struct PurchTicket {
    int row;
    int seat;
};


int FindResTicket(int reservedCount, int row, int seat, ResTicket* reservedTickets) {
    setlocale(LC_ALL, "Russian");
    for (int i = 0; i < reservedCount; i++) {
        if (reservedTickets[i].row == row && reservedTickets[i].seat == seat) {
            return i;
        }
    }
    return -1;
}

int FindResPurchTicket(int reservedTicketsCount, int row, int seat, std::string name, PurchTicket purchasedTickets[], int purchasedTicketsCount, ResTicket reservedTickets[]) {
    setlocale(LC_ALL, "Russian");
    for (int i = 0; i <= reservedTicketsCount; i++) {
        if (reservedTickets[i].row == row && reservedTickets[i].seat == seat) {
            if (reservedTickets[i].name == name)
            return i;
        }
    }
    return -1;
}

int FindPurchTicket(int purchasedCount, int row, int seat, PurchTicket* purchasedTickets) {
    setlocale(LC_ALL, "Russian");
    for (int i = 0; i < purchasedCount; i++) {
        if (purchasedTickets[i].row == row && purchasedTickets[i].seat == seat) {
            return i;
        }
    }
    return -1;
}

//--------------------------------------
void addReservedTicket(ResTicket reservedTickets[], int& reservedTicketsCount, int purchasedTicketsCount, PurchTicket purchasedTickets[], ResTicket& newTicket) {
    setlocale(LC_ALL, "Russian");
    if (reservedTicketsCount < MAX_SEATS) {
        std::cout << "Выберите ряд: ";
        std::cin >> newTicket.row;
        std::cout << "Выберите место: ";
        std::cin >> newTicket.seat;
        std::cout << "Запишите своё имя/фамилию: ";
        std::cin >> newTicket.name;

        if (newTicket.row > 10 || newTicket.row < 1 || newTicket.seat > 10 || newTicket.seat < 1) {
            std::cout << "Такого билета не существует. Выберите другую бронь." << std::endl;
            return;
        }

        reservedTickets[reservedTicketsCount] = newTicket;
        for (int i = 0; i < reservedTicketsCount; i++) {
            if (reservedTickets[i].row == reservedTickets[reservedTicketsCount].row && reservedTickets[i].seat == reservedTickets[reservedTicketsCount].seat) {
                std::cout << "Этот билет уже забронирован. Выберите другой. " << std::endl;
                return;
            }
        }
        if (FindPurchTicket(purchasedTicketsCount, reservedTickets[reservedTicketsCount].row, reservedTickets[reservedTicketsCount].seat, purchasedTickets) != -1) {
            std::cout << "Этот билет уже куплен. Забронируйте другой. " << std::endl;
        }
        else {
            reservedTicketsCount++;

            std::cout << "Билет успешно забронирован!" << std::endl;
            return;
        }
    }
    else {
        std::cout << "Список забронированных билетов полон, простите." << std::endl;
        return;
    }
}

void addPurchasedTicket(PurchTicket purchasedTickets[], int& purchasedTicketsCount, int& reservedTicketsCount, ResTicket* reservedTickets, PurchTicket& newTicket) {
    setlocale(LC_ALL, "Russian");
  
        if (purchasedTicketsCount < MAX_SEATS) {
            std::cout << "Выберите ряд: ";
            std::cin >> newTicket.row;
            std::cout << "Выберите место: ";
            std::cin >> newTicket.seat;

            if (newTicket.row > 10 || newTicket.row < 1 || newTicket.seat > 10 || newTicket.seat < 1) {
                std::cout << "Такого билета не существует. Выберите другой." << std::endl;
                return;
            }

            purchasedTickets[purchasedTicketsCount] = newTicket;
            for (int i = 0; i < purchasedTicketsCount; i++) {
                if (purchasedTickets[i].row == purchasedTickets[purchasedTicketsCount].row && purchasedTickets[i].seat == purchasedTickets[purchasedTicketsCount].seat) {
                    std::cout << "Этот билет уже Куплен. Выберите другой. " << std::endl;
                    return;
                }
            }
            if (FindResTicket(reservedTicketsCount, purchasedTickets[purchasedTicketsCount].row, purchasedTickets[purchasedTicketsCount].seat, reservedTickets) != -1) {
                std::cout << "Этот билет Забронирован. Купите другой. " << std::endl;
                return;
            }
            else {
                purchasedTicketsCount++;

                std::cout << "Билет успешно куплен" << std::endl;
                return;
            }
        }
        else {
            std::cout << "Список купленных билетов полон, простите." << std::endl;
            return;
        }
    }

void addFromReserved(PurchTicket purchasedTickets[], int& purchasedTicketsCount, ResTicket reservedTickets[], int& reservedTicketsCount, PurchTicket& newPurchTicket, ResTicket& newResTicket) {
    int row;
    int seat;
    std::string name;
    if (reservedTicketsCount == 0) {
        std::cout << "Список брони пуст. убирать нечего." << std::endl;
        return;
    }
    if (purchasedTicketsCount < MAX_SEATS) {
        std::cout << "Выберите ряд: ";
        std::cin >> row;
        std::cout << "Выберите место: ";
        std::cin >> seat;
        std::cout << "Запишите своё имя/фамилию: ";
        std::cin >> name;

        if (FindResPurchTicket(reservedTicketsCount, row, seat, name, purchasedTickets, reservedTicketsCount, reservedTickets) != -1) {
            purchasedTickets[purchasedTicketsCount].row = row;
            purchasedTickets[purchasedTicketsCount].seat = seat;
            purchasedTicketsCount++;
            std::cout << "Билет успешно куплен через бронь. " << std::endl;
            int index = FindResTicket(reservedTicketsCount, row, seat, reservedTickets);
             
            for (int i = index; i < reservedTicketsCount - 1; ++i) {
                reservedTickets[i] = reservedTickets[i + 1];
            }
            reservedTicketsCount--;
            return;

        }
        else if (FindResPurchTicket(reservedTicketsCount, row, seat, name, purchasedTickets, reservedTicketsCount, reservedTickets) == -1) {
            std::cout << "Подобная бронь не существует. " << std::endl;
            return;
        }
        else {
            std::cout << "Произошла ошибка. Попробуйте ещё раз. " << std::endl;
            return;
        }
    }
    else {
        std::cout << "Список купленных билетов полон. Простите. " << std::endl;
        return;
    }
}

//--------------------------------------------
void deleteResTicket(ResTicket tickets[], int& count) {
    setlocale(LC_ALL, "Russian");
    if (count == 0) {
        std::cout << "Список брони пуст. убирать нечего." << std::endl;
        return;
    }
    int row1;
    int seat1;
    std::cout << "Выберите ряд: ";
    std::cin >> row1;

    std::cout << "Выберите место: ";
    std::cin >> seat1;

    int index1 = FindResTicket(count, row1, seat1, tickets);
    if (index1 != -1) {
        if (index1 >= 0 && index1 < count) {
            for (int i = index1; i < count - 1; ++i) {
                tickets[i] = tickets[i + 1];
            }
            count--;
            std::cout << "Бронь успешно снята." << std::endl;
            return;
        }
        else {
            std::cout << "Произошла какая то ошибка. Проверьте место ещё раз." << std::endl;
            return;
        }
        return;
    }
    else {
        std::cout << "Подобная бронь не существует." << std::endl;
        return;
    }
}

void deletePurchTicket(PurchTicket tickets[], int& count) {
    setlocale(LC_ALL, "Russian");
    if (count == 0) {
        std::cout << "Список билетов пуст. Возвращать нечего." << std::endl;
        return;
    }
    int row2;
    int seat2;
    std::cout << "Выберите ряд: ";
    std::cin >> row2;

    std::cout << "Выберите место: ";
    std::cin >> seat2;

    int index2 = FindPurchTicket(count, row2, seat2, tickets);
    if (index2 != -1) {
        if (index2 >= 0 && index2 < count) {
            for (int i = index2; i < count - 1; ++i) {
                tickets[i] = tickets[i + 1];
            }
            count--;
            std::cout << "Вы вернули свой билет." << std::endl;
            return;
        }
        else {
            std::cout << "Произошла какая то ошибка. Проверьте место ещё раз." << std::endl;
            return;
        }
    }
    else {
        std::cout << "Такого билета не существует." << std::endl;
        return;
    }

}

//---------------------------------------
void editResTicket(ResTicket tickets[], int reservedTicketsCount, PurchTicket* purchasedTickets, int purchasedTicketsCount) {
    setlocale(LC_ALL, "Russian");
    if (reservedTicketsCount == 0) {
        std::cout << "Список брони пуст. изменять нечего." << std::endl;
        return;
    }
    int row5;
    int seat5;
    int newRow;
    int newSeat;
    std::cout << "Выберите ряд: ";
    std::cin >> row5;

    std::cout << "Выберите место: ";
    std::cin >> seat5;

    int index5 = FindResTicket(reservedTicketsCount, row5, seat5, tickets);
    if (index5 != -1) {
        std::cout << "Выберите новый ряд: ";
        std::cin >> newRow;

        std::cout << "Выберите новое место: ";
        std::cin >> newSeat;

        if (newRow > 10 || newRow < 1 || newSeat > 10 || newSeat < 1) {
            std::cout << "Такого билета не существует. Выберите другую бронь." << std::endl;
            return;
        }
        else {
            for (int i = 0; i < reservedTicketsCount; i++) {
                if (tickets[i].row == newRow && tickets[i].seat == newSeat) {
                    std::cout << "Этот билет уже забронирован. Выберите другой. " << std::endl;
                    return;
                }
            }
            if (FindPurchTicket(purchasedTicketsCount, newRow, newSeat, purchasedTickets) != -1) {
                std::cout << "Этот билет уже куплен. Забронируйте другой. " << std::endl;
                return;
            }
        }

        tickets[index5].row = newRow;
        tickets[index5].seat = newSeat;

        std::cout << "Бронь успешно изменена!" << std::endl;
        return;
    }
    else {
        std::cout << "Подобной брони не существует." << std::endl;
        return;
    }
}

void editPurchTicket(PurchTicket tickets[], int purchasedTicketsCount, ResTicket* reservedTickets, int reservedTicketsCount) {
    setlocale(LC_ALL, "Russian");
    if (purchasedTicketsCount == 0) {
        std::cout << "Список билетов пуст. изменять нечего." << std::endl;
        return;
    }
    int row6;
    int seat6;
    int newRow;
    int newSeat;
    std::cout << "Выберите ряд: ";
    std::cin >> row6;

    std::cout << "Выберите место: ";
    std::cin >> seat6;

    int index6 = FindPurchTicket(purchasedTicketsCount, row6, seat6, tickets);
    if (index6 != -1) {
        std::cout << "Выберите новый ряд: ";
        std::cin >> newRow;

        std::cout << "Выберите новое место: ";
        std::cin >> newSeat;

        if (newRow > 10 || newRow < 1 || newSeat > 10 || newSeat < 1) {
            std::cout << "Такого билета не существует. Выберите другой." << std::endl;
            return;
        }
        else {
            for (int i = 0; i < purchasedTicketsCount; i++) {
                if (tickets[i].row == newRow && tickets[i].seat == newSeat) {
                    std::cout << "Этот билет уже Куплен. Выберите другой. " << std::endl;
                    return;
                }
            }
            if (FindResTicket(reservedTicketsCount, newRow, newSeat, reservedTickets) != -1) {
                std::cout << "Этот билет Забронирован. Купите другой. " << std::endl;
                return;
            }
        }

        tickets[index6].row = newRow;
        tickets[index6].seat = newSeat;

        std::cout << "Билет успешно заменен!" << std::endl;
        return;
    }
    else {
        std::cout << "Такого билета не существует." << std::endl;
        return;
    }
}

//--------------------------------------
void printResTickets(ResTicket tickets[], int size) {
    setlocale(LC_ALL, "Russian");
    if (size == 0) {
        std::cout << "Список пустой. Выводить нечего." << std::endl;
        return;
    }

    for (int i = 0; i < size; ++i) {
        std::cout << "Ряд: " << tickets[i].row << ", Место: " << tickets[i].seat << ", Имя/Фамилия: " << tickets[i].name;

        std::cout << std::endl;
    }
    return;
}

void printPurchTickets(PurchTicket tickets[], int size) {
    setlocale(LC_ALL, "Russian");
    if (size == 0) {
        std::cout << "Список пустой. Выводить нечего." << std::endl;
        return;
    }

    for (int i = 0; i < size; ++i) {
        std::cout << "Ряд: " << tickets[i].row << ", Место: " << tickets[i].seat << std::endl;
    }
    return;
}

//-----------------------------------------

int main() {
    setlocale(LC_ALL, "Russian");

    ResTicket reservedTickets[MAX_SEATS];
    PurchTicket purchasedTickets[MAX_SEATS];
    ResTicket newResTicket;
    PurchTicket newPurchTicket;
    int reservedTicketsCount = 0;
    int purchasedTicketsCount = 0;
    int i1;
    int i2;

    int choice;
    do {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Забронировать билет" << std::endl;
        std::cout << "2. Купить билет" << std::endl;
        std::cout << "3. Отменить бронь" << std::endl;
        std::cout << "4. Вернуть купленный билет" << std::endl;
        std::cout << "5. Найти бронь" << std::endl;
        std::cout << "6. Найти купленный билет" << std::endl;
        std::cout << "7. Изменить бронь" << std::endl;
        std::cout << "8. Заменить купленный билет" << std::endl;
        std::cout << "9. Вывести список брони" << std::endl;
        std::cout << "10. Вывести список купленных билетов" << std::endl;
        std::cout << "11. Определить кол-во брони" << std::endl;
        std::cout << "12. Определить кол-во купленных билетов" << std::endl;
        std::cout << "13. Выкупить забронированный билет" << std::endl;
        std::cout << "14. Выйти" << std::endl;
        std::cout << "Введите свой выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            addReservedTicket(reservedTickets, reservedTicketsCount, purchasedTicketsCount, purchasedTickets, newResTicket);
            break;
        case 2:
            addPurchasedTicket(purchasedTickets, purchasedTicketsCount, reservedTicketsCount, reservedTickets, newPurchTicket);
            break;
        case 3:
            deleteResTicket(reservedTickets, reservedTicketsCount);
            break;
        case 4:
            deletePurchTicket(purchasedTickets, purchasedTicketsCount);
            break;
        case 5:
            if (reservedTicketsCount == 0) {
                std::cout << "Список брони пуст. искать нечего." << std::endl;
                break;
            }
            int row3;
            int seat3;

            std::cout << "Выберите ряд: ";
            std::cin >> row3;

            std::cout << "Выберите место: ";
            std::cin >> seat3;
            i1 = FindResTicket(reservedTicketsCount, row3, seat3, reservedTickets);
            if (i1 == -1) {
                std::cout << "Бронь не найдена." << std::endl;
                break;
            }
            else {
                std::cout << "Бронь найдена: " << reservedTickets[i1].name << std::endl;
                break;
            }
        case 6:
            if (purchasedTicketsCount == 0) {
                std::cout << "Список билетов пуст. искать нечего." << std::endl;
                break;
            }
            int row4;
            int seat4;

            std::cout << "Выберите ряд: ";
            std::cin >> row4;

            std::cout << "Выберите место: ";
            std::cin >> seat4;
            i2 = FindPurchTicket(purchasedTicketsCount, row4, seat4, purchasedTickets);
            if (i2 == -1) {
                std::cout << "Билет не найден." << std::endl;
                break;
            }
            else {
                std::cout << "Купленный билет найден." << std::endl;
                break;
            }
        case 7:
            editResTicket(reservedTickets, reservedTicketsCount, purchasedTickets, purchasedTicketsCount);
            break;
        case 8:
            editPurchTicket(purchasedTickets, purchasedTicketsCount, reservedTickets, reservedTicketsCount);
            break;
        case 9:
            if (reservedTicketsCount == 0) {
                std::cout << "Список брони пуст. выводить нечего." << std::endl;
                break;
            }
            printResTickets(reservedTickets, reservedTicketsCount);
            break;
        case 10:
            if (purchasedTicketsCount == 0) {
                std::cout << "Список билетов пуст. выводить нечего." << std::endl;
                break;
            }
            printPurchTickets(purchasedTickets, purchasedTicketsCount);
            break;
        case 11:
            std::cout << "Количество забронированных билетов: ";
            std::cout << reservedTicketsCount << std::endl;
            break;
        case 12:
            std::cout << "Количество купленных билетов: ";
            std::cout << purchasedTicketsCount << std::endl;
            break;
        case 13:
            addFromReserved(purchasedTickets, purchasedTicketsCount, reservedTickets, reservedTicketsCount, newPurchTicket, newResTicket);
            break;
        case 14:
            std::cout << "Выход с меню." << std::endl;
            break;
        default:
            std::cout << "Неккоретный выбор, попробуйте снова" << std::endl;
        }
    } while (choice != 14);

    return 0;
}