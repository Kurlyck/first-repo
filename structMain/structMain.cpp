#include <iostream>
#include <string>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");

    string text;
    string cipher;
    string decipher;
    string key = "251346";
    cout << "Введите текст для шифрования: ";
    getline(cin, text);
    cout << "Изначальный текст: " << text << std::endl;
    // Добавление пробелов, если длина текста не кратна 6
    int padding = 6 - (text.length() % 6);
    if (padding != 6) {
        text.append(padding, ' ');
    }
    // Шифрование текста
    for (int i = 0; i < text.length(); i += 6) {
        string blockCipher = text.substr(i, 6);
        string block = blockCipher;

        // Изменение порядка символов
        for (int j = 0; j < 6; j++) {
            blockCipher[key[j] - '1'] = block[j];
        }

        cipher += blockCipher;
    }
    cout << "Зашифрованный текст: " << cipher << std::endl;

    // Дешифрование текста
    for (int i = 0; i < text.length(); i += 6) {
        string block = cipher.substr(i, 6);
        string blockDecipher = block;

        // Изменение порядка символов
        for (int j = 0; j < 6; j++) {
            blockDecipher[j] = block[key[j] - '1'];
        }

        decipher += blockDecipher;
    }

    cout << "Задешифрованный текст: " << decipher << std::endl;

    return 0;
}

