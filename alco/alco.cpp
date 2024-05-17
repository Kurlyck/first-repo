#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

struct Card {
    int value;
    char suit;
};

struct Node {
    Card card;
    Node* next;
};

void deleteCard(Node** tail) {
    Node* temp = *tail;
    if (temp->next == temp) {
        *tail = nullptr;
    }
    else {
        temp->next = temp->next->next;
        *tail = temp;
    }
    return;
}

std::vector<Card> createDeck() {
    std::vector<Card> deck;
    for (int value = 6; value <= 14; ++value) {
        for (char suit : {'H', 'B', 'K', 'S'}) {
            deck.push_back({ value, suit });
        }
    }
    return deck;
}

void shuffleDeck(std::vector<Card>& deck) {
    std::srand(std::time(nullptr));
    for (int i = 0; i < deck.size(); ++i) {
        int randomIndex = std::rand() % deck.size();
        std::swap(deck[i], deck[randomIndex]);
    }
}

Node* addForWinNode(Node* end, int value, char suit) {
    Node* newNode = new Node;
    newNode->card.value = value;
    newNode->card.suit = suit;
    if (end == nullptr) {
        newNode->next = newNode;
    }
    else {
        newNode->next = end->next;
        end->next = newNode;
    }
    return newNode;
}

Node* addNode(Node* end, Card card) {
    Node* newNode = new Node;
    newNode->card = card;
    if (end == nullptr) {
        newNode->next = newNode;
    }
    else {
        newNode->next = end->next;
        end->next = newNode;
    }
    return newNode;
}

void printList(Node* end) {
    if (end != nullptr) {
        Node* temp = end->next;
        do {
            std::cout << temp->card.value << temp->card.suit << " ";
            temp = temp->next;
        } while (temp != end->next);
    }
    std::cout << std::endl;
}

int compareCards(Node* card1, Node* card2) {
    Node* temp1 = card1;
    Node* temp2 = card2;
    if (temp1->next->card.value > temp2->next->card.value) {
        return 1;
    }
    else if (temp1->next->card.value < temp2->next->card.value) {
        return 2;
    }
    else {
        // Сравниваем по мастям
        if (temp1->next->card.suit == 'H' && temp2->next->card.suit != 'H') {
            return 1;
        }
        else if (temp1->next->card.suit == 'B' && temp2->next->card.suit != 'H' && temp2->next->card.suit != 'B') {
            return 1;
        }
        else if (temp1->next->card.suit == 'K' && temp2->next->card.suit == 'S') {
            return 1;
        }
        else {
            return 2;
        }
    }
}

int main() {
    Node* player1End = nullptr;
    Node* player2End = nullptr;
    int choose;

    std::vector<Card> deck = createDeck();
    shuffleDeck(deck);

    for (int i = 0; i < 18; ++i) {
        player1End = addNode(player1End, deck[i]);
        player2End = addNode(player2End, deck[i + 18]);
    }

    std::cout << "Player 1's cards: ";
    printList(player1End);
    std::cout << "Player 2's cards: ";
    printList(player2End);

    std::cout << "Start game? (1/0)" << std::endl;
    std::cin >> choose;
    if (choose == 1) {
        int steps = 0;
        while (player1End != nullptr && player2End != nullptr) {
            steps++;
            std::cout << "Step " << steps << std::endl;
            std::cout << "Player 1: " << player1End->next->card.value << player1End->next->card.suit << std::endl;
            std::cout << "Player 2: " << player2End->next->card.value << player2End->next->card.suit << std::endl;

            int result = compareCards(player1End, player2End);
            if (result == 1) {
                player1End = addForWinNode(player1End, player1End->next->card.value, player1End->next->card.suit);
                player1End = addForWinNode(player1End, player2End->next->card.value, player2End->next->card.suit);
                deleteCard(&player1End);
                deleteCard(&player2End);
                player1End = player1End->next;
                player2End = player2End->next;
                std::cout << "Player 1's cards: ";
                printList(player1End);
                std::cout << "Player 2's cards: ";
                printList(player2End);
                std::cout << "Player 1 wins the round!" << std::endl;
            }
            else if (result == 2) {
                player2End = addForWinNode(player2End, player1End->next->card.value, player1End->next->card.suit);
                player2End = addForWinNode(player2End, player2End->next->card.value, player2End->next->card.suit);
                deleteCard(&player2End);
                deleteCard(&player1End);
                player2End = player2End->next;
                player1End = player1End->next;
                std::cout << "Player 1's cards: ";
                printList(player1End);
                std::cout << "Player 2's cards: ";
                printList(player2End);
                std::cout << "Player 2 wins the round!" << std::endl;
            }
  
            std::cout << std::endl;
        }

        if (player1End == nullptr) {
            std::cout << "Player 2 wins the game!" << std::endl;
        }
        else {
            std::cout << "Player 1 wins the game!" << std::endl;
        }
    }

    return 0;
}
