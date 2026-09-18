#include <iostream>

using namespace std;

int main() {
    char message[1000];

    cout << "Enter the message: ";
    cin >> message;

    cout << "Encrypted message: ";

    // The first letter does not change
    cout << message[0];

    for (int i = 1; message[i] != '\0'; i++) {
        int currentValue = message[i] - 'A' + 1;
        int previousValue = message[i - 1] - 'A' + 1;

        int newValue = currentValue + previousValue;

        while (newValue > 26) {
            newValue = newValue - 26;
        }

        char encryptedCharacter = 'A' + newValue - 1;

        cout << encryptedCharacter;
    }

    cout << endl;

    return 0;
}
