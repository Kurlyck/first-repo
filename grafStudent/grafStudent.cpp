#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Email {
    

};

int main() {
    setlocale(LC_ALL, "Russian");

    int n; 
    cout << "Введите количество людей: ";
    cin >> n;

    vector<string> names(n);
    for (int i = 0; i < n; i++) {
        cout << "Введите имя человека " << i + 1 << ": ";
        cin >> names[i];
    }

    vector<vector<int>> adj_matrix(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                cout << "Введите количество сообщений от " << names[i] << " к " << names[j] << ": ";
                cin >> adj_matrix[i][j];
            }
        }
    }

    cout << "Список переписки:" << endl;
    for (int i = 0; i < n; i++) {
        cout << names[i] << ": ";
        for (int j = 0; j < n; j++) {
            if (adj_matrix[i][j] > 0) {
                cout << names[j] << " (" << adj_matrix[i][j] << "), ";
            }
        }
        cout << endl;
    }

    return 0;
}

