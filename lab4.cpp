#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Структура для хранения информации о медучреждении
struct MedicalFacility {
    string name;
    string type;
    string specialization;
};

// Функция для создания графа заданной конфигурации
vector<vector<bool>> createGraph() {
    // Исходный граф
    vector<MedicalFacility> facilities = {
        {"Больница 1", "Стационар", "Общая медицина"},
        {"Поликлиника 1", "Поликлиника", "Терапия"},
        {"Лаборатория 1", "Лаборатория", "Анализы"},
        {"Больница 2", "Стационар", "Хирургия"},
        {"Поликлиника 2", "Поликлиника", "Педиатрия"}
    };

    int n = facilities.size();
    vector<vector<bool>> adjacency_matrix(n, vector<bool>(n, false));

    // Создание связей между медучреждениями
    adjacency_matrix[0][1] = adjacency_matrix[1][0] = true;
    adjacency_matrix[1][2] = adjacency_matrix[2][1] = true;
    adjacency_matrix[0][3] = adjacency_matrix[3][0] = true;
    adjacency_matrix[3][4] = adjacency_matrix[4][3] = true;

    return adjacency_matrix;
}

// Функция для добавления ребра в граф
void addEdge(vector<vector<bool>>& adjacency_matrix, int u, int v) {
    adjacency_matrix[u][v] = adjacency_matrix[v][u] = true;
}

// Функция для удаления ребра из графа
void removeEdge(vector<vector<bool>>& adjacency_matrix, int u, int v) {
    adjacency_matrix[u][v] = adjacency_matrix[v][u] = false;
}

// Функция для вывода информации о смежных вершинах
void printAdjacentVertices(const vector<vector<bool>>& adjacency_matrix, const vector<MedicalFacility>& facilities) {
    for (int i = 0; i < adjacency_matrix.size(); i++) {
        cout << "Смежные вершины для " << facilities[i].name << ":" << endl;
        for (int j = 0; j < adjacency_matrix[i].size(); j++) {
            if (adjacency_matrix[i][j]) {
                cout << "- " << facilities[j].name << endl;
            }
        }
        cout << endl;
    }
}

int main() {
    // Создание графа
    vector<vector<bool>> adjacency_matrix = createGraph();

    // Вывод информации о смежных вершинах
    vector<MedicalFacility> facilities = {
        {"Больница 1", "Стационар", "Общая медицина"},
        {"Поликлиника 1", "Поликлиника", "Терапия"},
        {"Лаборатория 1", "Лаборатория", "Анализы"},
        {"Больница 2", "Стационар", "Хирургия"},
        {"Поликлиника 2", "Поликлиника", "Педиатрия"}
    };
    printAdjacentVertices(adjacency_matrix, facilities);

    // Добавление ребра
    addEdge(adjacency_matrix, 1, 3);

    // Вывод информации о смежных вершинах после добавления ребра
    cout << "После добавления ребра:" << endl;
    printAdjacentVertices(adjacency_matrix, facilities);

    // Удаление ребра
    removeEdge(adjacency_matrix, 0, 1);

    // Вывод информации о смежных вершинах после удаления ребра
    cout << "После удаления ребра:" << endl;
    printAdjacentVertices(adjacency_matrix, facilities);

    return 0;
}
