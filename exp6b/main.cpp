//4.	Write a program for distance vector algorithm to find suitable path for transmission.

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

const int INF = 999;

void print_tables(const vector<char>& routers, const vector<vector<int>>& dist, const vector<vector<int>>& next_hop) {
    int n = routers.size();
    for (int i = 0; i < n; i++) {
        cout << "\nRouter " << routers[i] << " Routing Table:\n";
        cout << "Destination | Cost | Next Hop\n";
        for (int j = 0; j < n; j++) {
            string cost_str = (dist[i][j] >= INF ? "INF" : to_string(dist[i][j]));
            cout << " " << routers[j] << " | " << setw(4) << cost_str << " | " << routers[next_hop[i][j]] << "\n";
        }
        cout << string(30, '-') << "\n";
    }
}

void distance_vector_routing(int n, const vector<char>& routers, const vector<vector<int>>& cost) {
    vector<vector<int>> dist = cost;
    vector<vector<int>> next_hop(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            next_hop[i][j] = j;

    cout << "\nInitial distance tables:\n";
    print_tables(routers, dist, next_hop);

    bool updated = true;
    int iteration = 0;

    while (updated) {
        updated = false;
        iteration++;
        cout << "\n=== Iteration " << iteration << " ===\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (dist[i][j] > cost[i][k] + dist[k][j]) {
                        dist[i][j] = cost[i][k] + dist[k][j];
                        next_hop[i][j] = k;
                        updated = true;
                    }
                }
            }
        }
        print_tables(routers, dist, next_hop);
    }

    cout << "\nConverged after " << iteration << " iteration(s).\n";
}

int main() {
    int n;
    cout << "Enter the number of routers: ";
    cin >> n;

    vector<char> routers(n);
    for (int i = 0; i < n; i++)
        routers[i] = 'A' + i;

    cout << "\nEnter the cost matrix (use 999 for infinity):\n";
    vector<vector<int>> cost(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    distance_vector_routing(n, routers, cost);
    return 0;
}

