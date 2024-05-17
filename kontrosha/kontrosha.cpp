#include <iostream>

struct Node {
    Node* pLink;
    int Info;
};

int isListSorted(Node* head) {
    //Проверка на пустоту списка
    if (head == nullptr) {
        return -1;
    }
    //Перебор всех элементов на проверку упорядоченности
    Node* current = head;
    while (current->pLink != nullptr) {
        if (current->Info > current->pLink->Info) {
            return 0;
        }
        current = current->pLink;
    }

    return 1;
}

int main() {
    setlocale(LC_ALL, "Russian");

    // Пример
    Node* head = nullptr;
    Node* first = new Node;
    first->Info = 3;
    first->pLink = head;
    head = first;

    Node* second = new Node;
    second->Info = 2;
    second->pLink = head;
    head = second;

    Node* third = new Node;
    third->Info = 1;
    third->pLink = head;
    head = third;

    Node* current = head;
    while (current != nullptr) {
        std::cout << current->Info << " ";
        current = current->pLink;
    }

    /*Node* second = new Node;
    second->Info = 2;
    head->pLink = second;

    Node* third = new Node;
    third->Info = 3;
    second->pLink = third;*/

    // Проверка упорядоченности списка
    if (isListSorted(head) == 1) {
        std::cout << "Список упорядочен по неубыванию" << std::endl;
    }
    else if (isListSorted(head) == 0) {
        std::cout << "Список не упорядочен по неубыванию" << std::endl;
    }
    else {
        std::cout << "Список пуст." << std::endl;
    }

    /*// Пример списка, который не упорядочен
    Node* headUnsorted = new Node;
    headUnsorted->Info = 5;

    Node* secondUnsorted = new Node;
    secondUnsorted->Info = 3;
    headUnsorted->pLink = secondUnsorted;

    Node* thirdUnsorted = new Node;
    thirdUnsorted->Info = 8;
    secondUnsorted->pLink = thirdUnsorted;

    // Проверка упорядоченности списка
    if (isListSorted(headUnsorted)) {
        std::cout << "Список упорядочен по неубыванию" << std::endl;
    }
    else {
        std::cout << "Список не упорядочен по неубыванию" << std::endl;
    }*/

    return 0;
}
