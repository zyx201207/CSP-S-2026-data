#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e5 + 5;
const int M = 3e5 + 5;
int n, m;
ll a[N], b[M], d[M];
bool c[M];
stack<ll> q;

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        memset(b, 0, sizeof(b));
        memset(c, false, sizeof(c));
        for (int j = i; j <= n; j++){
            b[a[j]]++;
            c[a[j]] = 1;
            if (b[a[j]] > 1) {
                while (q.top() != a[j]) {
                    c[q.top()] = 0;
                    b[q.top()]--;
                    q.pop();
                }
                b[a[j]] = 1;
            }
            q.push(a[j]);
        }
        for (int j = 1; j <= m; j++) {
            if (c[j] == 1) d[j]++;
        }
    }
    for (int i = 1; i <= m; i++) cout << d[i] << " ";
    return 0;
}
