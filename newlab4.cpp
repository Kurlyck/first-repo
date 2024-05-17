#include <iostream>
#include <vector>
#include <string>

// Структура для хранения информации о медучреждении
struct MedicalFacility {
    std::string name;
    std::string type;
    std::string specialization;
};

// Функция для создания графа заданной конфигурации
std::vector<std::vector<int>> createGraph(const std::vector<MedicalFacility> facilities) {
    int n = facilities.size();
    std::vector<std::vector<int>> graph(n, std::vector<int>(n, 0));

    // Создаем связи между вершинами
    graph[0][1] = 1;
    graph[1][0] = 1;
    graph[1][2] = 1;
    graph[2][1] = 1;
    graph[2][3] = 1;
    graph[3][2] = 1;
    graph[3][4] = 1;
    graph[4][3] = 1;

    return graph;
}

// Функция для добавления вершины в граф
std::vector<std::vector<int>> addVertex(std::vector<std::vector<int>> graph, const MedicalFacility& facility) {
    int n = graph.size();
    graph.resize(n + 1);
    for (int i = 0; i < n; i++) {
        graph[i].push_back(0);
    }
    graph.push_back(std::vector<int>(n + 1, 0));
    return graph;
}

// Функция для удаления вершины из графа
std::vector<std::vector<int>> removeVertex(std::vector<std::vector<int>> graph, int index) {
    int n = graph.size();
    graph.erase(graph.begin() + index);
    for (int i = 0; i < n - 1; i++) {
        graph[i].erase(graph[i].begin() + index);
    }
    return graph;
}

// Функция для добавления ребра между двумя вершинами
std::vector<std::vector<int>> addEdge(std::vector<std::vector<int>> graph, int v1, int v2) {
    graph[v1][v2] = 1;
    graph[v2][v1] = 1;
    return graph;
}

// Функция для удаления ребра между двумя вершинами
std::vector<std::vector<int>> removeEdge(std::vector<std::vector<int>> graph, int v1, int v2) {
    graph[v1][v2] = 0;
    graph[v2][v1] = 0;
    return graph;
}

// Функция для вывода информации о смежных вершинах
void printAdjacentVertices(std::vector<std::vector<int>> graph, std::vector<MedicalFacility> facilities) {
    for (int i = 0; i < graph.size(); i++) {
        std::cout << "Смежные вершины для " << facilities[i].name << ":" << std::endl;
        for (int j = 0; j < graph[i].size(); j++) {
            if (graph[i][j]) {
                std::cout << "  " << facilities[j].name << std::endl;
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    // Создаем медучреждения
    std::vector<MedicalFacility> facilities = {
        {"Городская больница", "Стационар", "Общая медицина"},
        {"Поликлиника №1", "Поликлиника", "Терапия"},
        {"Диагностический центр", "Лаборатория", "Диагностика"},
        {"Детская поликлиника", "Поликлиника", "Педиатрия"},
        {"Стоматологическая клиника", "Поликлиника", "Стоматология"}
    };

    // Создаем граф
    std::vector<std::vector<int>> graph = createGraph(facilities);

    // Добавляем новую вершину
    MedicalFacility newFacility = {"Реабилитационный центр", "Стационар", "Реабилитация"};
    graph = addVertex(graph, newFacility);

    // Добавляем ребро между двумя вершинами
    graph = addEdge(graph, 0, 5);

    // Удаляем ребро между двумя вершинами
    graph = removeEdge(graph, 0, 5);

    // Удаляем вершину
    graph = removeVertex(graph, 2);

    // Выводим информацию о смежных вершинах
    printAdjacentVertices(graph, facilities);

    return 0;
}
