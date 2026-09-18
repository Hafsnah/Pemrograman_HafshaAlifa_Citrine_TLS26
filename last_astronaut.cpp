#include <iostream>

using namespace std;

int main() {
    int N, K;

    cout << "Enter number of astronauts (N): ";
    cin >> N;

    cout << "Enter initial value of K: ";
    cin >> K;

    if (N <= 0 || K < 2) {
        cout << "Invalid input." << endl;
        return 0;
    }

    bool* alive = new bool[N];

    for (int i = 0; i < N; i++) {
        alive[i] = true;
    }

    int remaining = N;
    int current = 0;

    cout << "Elimination order: ";

    while (remaining > 1) {
        int count = 0;

        while (count < K) {
            if (alive[current]) {
                count++;
            }

            if (count == K) {
                break;
            }

            current++;

            if (current == N) {
                current = 0;
            }
        }

        int eliminated = current + 1;

        cout << eliminated << " ";

        alive[current] = false;
        remaining--;

        if (eliminated % 2 == 0) {
            K = K + 2;
        } else {
            K = K - 1;

            if (K < 2) {
                K = 2;
            }
        }

        current++;

        if (current == N) {
            current = 0;
        }

        while (!alive[current]) {
            current++;

            if (current == N) {
                current = 0;
            }
        }
    }

    cout << endl;

    for (int i = 0; i < N; i++) {
        if (alive[i]) {
            cout << "Last astronaut: " << i + 1 << endl;
        }
    }

    delete[] alive;

    return 0;
}
