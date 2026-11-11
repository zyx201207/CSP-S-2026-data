#include <bits/stdc++.h>
using namespace std;

int n, m, a[500005], c[300005];
stack<int> s;
bool b[300005];

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
        memset(b, false, sizeof(b));
        s = stack<int>();
        for (int j = i; j <= n; j++) {
            if (!b[a[j]]) {
                s.push(a[j]);
                b[a[j]] = true;
            }
            else {
                while (s.top() != a[j]) {
                    b[s.top()] = false;
                    s.pop();
                }

            }
        }
        while (!s.empty()) {
            c[s.top()]++;
            s.pop();
        }
    }
    for(int i = 1; i <= m; i++)
        printf("%d ", c[i]);
    return 0;
}
