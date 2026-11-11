#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], ans[300005];
bool v[300005];
void play(int l, int r) {
    int i = l, j = l+1;
    memset(v, 0, sizeof(v));
    queue<int> q;
    q.push(a[i]);
    v[a[i]] = 1;
    while (j <= r) {
        q.push(a[j]);
        if (v[a[j]]) {
            while(q.front() != a[j]) {
                int x = q.front();
                q.pop();
                q.push(x);
            }
            q.pop();

            while (q.front() != a[j]) {
                    v[q.front()] = 0;
                    q.pop();
            }
            int x = q.front();
            q.pop();
            q.push(x);
            i = j++;
        }
        else v[a[j++]] = 1;
    }
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        ans[p]++;
    }
}
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        play(i, n);
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
    return 0;
}
