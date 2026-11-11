#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> cards(n), vis(m + 1, -1), app(m + 1, 0);
    for (int i = 0; i < n; i ++) cin >> cards[i];
    vector<int> sat;
    for (int i = 0; i < n; i ++) {
        sat.resize(0);
        for (int j = i; j < n; j ++) {
            sat.push_back(cards[j]);
            if (vis[cards[j]] == -1) vis[cards[j]] = sat.size();
            else {
                sat.resize(vis[cards[j]]);
                for (int i = 0; i < m; i ++) {
                    if (vis[i] >= sat.size()) vis[i] == -1;
                }
            }
            
        }
        for (int j = 0; j < sat.size(); j ++) {
            app[sat[j]] ++;
        }
    }
    for (int i = 1; i < m; i ++) cout << app[i] << ' ';
    cout << app[m];
    return 0;
}