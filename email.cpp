#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int n = 5;

struct Email {
    vector<string> names(n);
    vector<vector<int>> adj_matrix(n, vector<int>(n, 0));
} A;

int main() {
    setlocale(LC_ALL, "Russian");

    //int n; 
    cout << "Количество людей: " << n;
    //cin >> n;

    //vector<string> names(n);
    for (int i = 0; i < n; i++) {
        cout << "Введите имя человека " << i + 1 << ": ";
        cin >> A.names[i];
    }

    //vector<vector<int>> adj_matrix(n, vector<int>(n, 0));

    int m; // количество ребер
    cout << "Введите количество ребер: ";
    cin >> m;
    for (int i = 0; i < m; i++) {
        string from;
        string to;
        int weight;
        cout << "Введите номер отправителя, номер получателя и вес ребра: ";
        cin >> from >> to >> weight;
        A.adj_matrix[from].push_back(make_pair(to, weight));
    }
    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                cout << "Введите количество сообщений от " << names[i] << " к " << names[j] << ": ";
                cin >> adj_matrix[i][j];
            }
        }
    }*/

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