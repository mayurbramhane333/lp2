#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& arr, int x, int y, int n) {
    // Check if there is a queen in the same column
    for (int row = 0; row < x; row++) {
        if (arr[row][y] == 1) {
            return false;
        }
    }

    // Check if there is a queen in the upper-left diagonal
    int row = x;
    int col = y;
    while (row >= 0 && col >= 0) {
        if (arr[row][col] == 1) {
            return false;
        }
        row--;
        col--;
    }

    // Check if there is a queen in the upper-right diagonal
    row = x;
    col = y;
    while (row >= 0 && col < n) {
        if (arr[row][col] == 1) {
            return false;
        }
        row--;
        col++;
    }

    return true;
}

bool nQueen(vector<vector<int>>& arr, int x, int n) {
    if (x >= n) {
        return true;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(arr, x, col, n)) {
            arr[x][col] = 1;
            if (nQueen(arr, x + 1, n)) {
                return true;
            }
            arr[x][col] = 0;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n, 0));

    if (nQueen(arr, 0, n)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    else{
        cout<<"Solution not possible !";
    }





    return 0;
}
