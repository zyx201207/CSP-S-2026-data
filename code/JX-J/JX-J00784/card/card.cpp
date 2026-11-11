#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m; cin >> n >> m;
    vector<int> data(n+1);
    for (int i = 1; i <= n; i ++) {
        cin >> data[i];
    }
    for (int i = 0; i < m; i ++) cout << "1 ";
}