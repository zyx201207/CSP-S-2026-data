#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m, a[500001], c[300001] = {0};
    bool f[300001];
    stack<int> s;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        memset(f, false, sizeof(f));
        for (int j = i; j <= n; j++)
            if (f[a[j]])
                while (s.top() != a[j])
                    s.pop();
            else {
                f[a[j]] = true;
                s.push(a[j]);
            }
        while (!s.empty()) {
            c[s.top()]++;
            s.pop();
        }
    }
    for (int i = 1; i <= m; i++)
        cout << c[i] << ' ';
    return 0;
}
