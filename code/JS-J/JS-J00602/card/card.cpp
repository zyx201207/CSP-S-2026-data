#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 9;
int n, m;
int ans[N];
int a[N];

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        vector<int> table;
        map<int, int> m;
        for (int j = i; j <= n; j++) {
            if (m[a[j]] == 1) {
                int last = -1;
                while (last != a[j]) {
                    last = table.back();
                    m[last] = 0;
                    table.pop_back();
                }
            }
            table.push_back(a[j]);
            m[a[j]] = 1;
        }
        for (int v : table) ans[v]++;
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << " ";

    return 0;
}
