#include <bits/stdc++.h>

using namespace std;

int n, m; //n là số đỉnh, m là số cạnh.
vector<pair<int, int>> adj[1001]; // cạnh kề
bool used[1001]; // used[i] == true => i thuộc V(MST); used[i] == false => i thuộc V

struct canh {
    int x, y, w;
};

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, w; cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    memset(used, false, sizeof(used));
}

void prim(int u) {
    //Bước 1: Đặt đỉnh u trong V(MST)
    vector<canh> MST;
    int d = 0;
    used[u] = true; // đưa đỉnh u vào V(MST)
    while (MST.size() < n - 1) {
        // Tìm cạnh ngắn nhất của cạnh kề đỉnh u.
        int min = INT_MAX;
        int X, Y;
        for (int i = 1; i <= n; i++) {
            if (used[i]) { //Nếu đỉnh i thuộc V(MST)
                for (pair<int, int> t: adj[i]) { //Với mọi cạnh kề của đỉnh i
                    int j = t.first, trongso = t.second;
                    if (!used[j] && trongso < min) {
                        min = trongso;
                        X = j, Y = i;
                    }
                }
            }
        }
        d += min;
        MST.push_back({X, Y, min});
        used[X] = true;
    }
    
    cout << d << endl;
    for (canh e: MST) {
        cout << e.x << " " << e.y << " " << e.w << endl;
    }
}

int main() {
    input();
    prim(1);
    return 0;
}
