
#include <iostream>
using namespace std;

int main() {
    int n, cost[10][10], dist[10][10];
    int temp[10][10];

    cout << "Enter number of routers: ";
    cin >> n;

    cout << "Enter cost matrix (999 for no connection):\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
            dist[i][j] = cost[i][j];
        }
    }

    bool updated;

    do {
        updated = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp[i][j] = dist[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {

                if (cost[i][k] == 999)
                    continue;

                for (int j = 0; j < n; j++) {

                    if (dist[k][j] != 999 &&
                        cost[i][k] + dist[k][j] < temp[i][j]) {

                        temp[i][j] = cost[i][k] + dist[k][j];
                        updated = true;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = temp[i][j];
            }
        }

    } while (updated);

    cout << "\nFinal Distance Table:\n";

    for (int i = 0; i < n; i++) {
        cout << "Router " << i + 1 << ":\n";

        for (int j = 0; j < n; j++) {
            cout << dist[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}

