#include <bits/std++.h>
using namespace std;
const int N = 512, M = 5e5 + 10;
int c, n, m, d, q, k;
int book[M];
int x, y;
long long w[M];
int a[M];
vectr <int> e;
queue <int> q;
void bfs(int n) {
    for (auto a : e[n]) {
        q.push(x);
    }
    while (!q.empty()) {
        auto tmp = q.top();
        q.pop();
        if (book[tmp] > book[n] + k)
    }
    return;
}
int main() {
    cin >> c >> n >> m >> d >> q;
    e.resize(m);
    for (int i = 1; i <= m; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++) {
            memset(a, 0, sizeof a);
        cin >> k;
        for (int j = 1; j <= k; j++) {
            cin >> a[j];
            if (j > 1) {
                e[a[j]].push_back(a[j - 1]);
                e[a[j - 1]].push_back(a[j]);
            }
        }
    }
    for (int i = 1; i <= q; i++) {
        memset(book, 0, sizeof book);
        cin >> x >> y;

    }
    return 0;
}
