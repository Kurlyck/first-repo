#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
struct Card
{
    int value;
    string suit;
    Card *next;
};

Card* insertCard(Card* queue, int value, string sign) {
    Card* newCard = new Card;
    newCard->value = value;
    newCard->suit = sign;
    if (queue != nullptr) {
        newCard->next = queue->next;
        queue->next = newCard;
        return newCard;
    }
    else {
        newCard->next = newCard;
        return newCard;
    }
    return newCard;
}

bool isCardInList(Card* last, int value, string suit) {
    if (last == nullptr) {
        return false;
    }

    Card* current = last->next;
    do {
        if (current->value == value && current->suit == suit) {
            return true;
        }
        current = current->next;
    } while (current != last->next);

    return false;
}

int countCardsWithValue(Card* last, int value) {
    if (last == nullptr) {
        return 0;
    }

    int count = 0;
    Card* current = last->next;
    do {
        if (current->value == value) {
            count++;
        }
        current = current->next;
    } while (current != last->next);

    return count;
}

int addCardToDeck(Card* last, int value, string suit, int i) {
    if (isCardInList(last, value, suit) || countCardsWithValue(last, value) >= 4) {
        return i - 1;
    }

    last = insertCard(last, value, suit);
    /*Card* newCard = new Card;
    newCard->value = value;
    newCard->suit = suit;
    if (last != nullptr) {
        newCard->next = last->next;
        last->next = newCard;
        last = newCard;
        return i;
    }
    else {
        newCard->next = newCard;
        last = newCard;
        return i;
    }*/
    return i;
}

void createDeck(Card* last, int deck) {
    string suits[] = { "Chervi", "Piki", "Kresti", "Buby" };
    /*int value = rand() % 9 + 6;
    string suit = suits[rand() % 4];
    Card* newCard = new Card;
    newCard->value = value;
    newCard->suit = suit;
    newCard->next = newCard;
    last = newCard;*/

    for (int i = 0; i < deck; ++i) {
        int value = rand() % 9 + 6;
        string suit = suits[rand() % 4];
        i = addCardToDeck(last, value, suit, i);
    }
    return;
}

void dragCard(Card* tail, int& count) {
    setlocale(LC_ALL, "Russian");

    if (tail == nullptr) {
        std::cout << "Колода пустая" << std::endl;
        return;
    }

    std::cout << "Ваша карта: " << tail->next->value << " " << tail->next->suit << std::endl;

    if (tail->next == tail) {
        tail = nullptr;
        count--;
        return;
    }
    else {
        tail->next = tail->next->next;
        tail = tail->next;
        count--;
        return;
    }
    return;
}

void deleteCard(Card* tail, int& count) {
    if (tail == nullptr) {
        std::cout << "Колода пустая" << std::endl;
        return;
    }

    if (tail->next == tail) {
        tail = nullptr;
        count--;
        return;
    }
    else {
        tail->next = tail->next->next;
        tail = tail->next;
        count--;
        return;
    }
    return;
}

void printSteck(Card* last, int count) {
    if (last == nullptr) {
        std::cout << "Список пуст" << std::endl;
        return;
    }

    Card* current = last->next;
    do {
        std::cout << current->value << " " << current->suit << " " << endl;
        current = current->next;
    } while (current != last->next);
    std::cout << std::endl;

    /*Card* temp = last->next;
    for (int i = count; i >= 1; i--) {
        cout << temp->value << " " << temp->suit << endl;
        temp = temp->next;
    }*/
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int choose;
    Card* last = nullptr;
    int number;
    string rank;
    int count = 0;
    unsigned int currentTime = static_cast<unsigned int>(time(0));
    srand(currentTime);

    //srand(time(0));

    do {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Положить карту в конец колоды" << std::endl;
        std::cout << "2. Вытянуть карту с верха колоды" << std::endl;
        std::cout << "3. Убрать карту с верха колоды" << std::endl;
        std::cout << "4. Посмотреть какие карты остались" << std::endl;
        std::cout << "5. Создать колоду из 36 карт" << std::endl;
        std::cout << "6. Выйти" << std::endl;
        std::cout << "Введите свой выбор: ";
        std::cin >> choose;

        switch (choose) {
        case 1:
            cout << "Введите число: ";
            cin >> number;
            cout << "Выберите масть: ";
            cin >> rank;
            last = insertCard(last, number, rank);
            count++;
            break;
        case 2:
            dragCard(last, count);
            break;
        case 3:
            deleteCard(last, count);
            break;
        case 4:
            printSteck(last, count);
            break;
        case 5:
            createDeck(last, 36);
            break;
        case 6:
            cout << "\nВыход из игры" << endl;
            break;
        default:
            cout << "\nВыберите что то другое" << endl;
        }
    } while (choose != 6);

    return 0;
}