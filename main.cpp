#include <bits/stdc++.h>

using namespace std;

int board[1001][1001];
int n = 8;
int mx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int my[8] = {1, 2, 2, 1, -1, -2, -2, -1};
bool visited[1001][1001];

int B = 0;

void get_step(int x, int y) {
    int neighbors[8] = {10, 10, 10, 10, 10, 10, 10, 10};
    for (int i = 0; i < 8; i++) {
        int next_x = x + mx[i];
        int next_y = y + my[i];
        if (next_x >= 0 && next_x < 8 && next_y >= 0 && next_y < 8 && !visited[next_x][next_y]) {
            int count = 0;
            for (int j = 0; j < 8; j++) {
                int nx = next_x + mx[j];
                int ny = next_y + my[j];
                if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && !visited[nx][ny]) {
                    count++;
                }
            }
            neighbors[i] = count;
        }
    }
    
    //get lowest
    int temp = 9;
    for (int i = 0; i < 8; i++) {
        if (neighbors[i] < temp) {
            temp = neighbors[i];
            B = i;
        }
    }
}

void solve(int vx, int vy) {
    int x = vx - 1;
    int y = vy - 1;
    board[x][y] = 0;
    visited[x][y] = true;
    for (int i = 1; i <= 64; i++) {
        get_step(x, y);
        x = x + mx[B];
        y = y + my[B];
        visited[x][y] = true;
        // cout << x << " " << y << endl;
        board[x][y] = i;
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    solve(1, 1);
    return 0;
}