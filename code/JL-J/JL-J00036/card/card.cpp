#include<bits/stdc++.h>
using namespace std;
const int N = 500005, M = 300005;
int n, m, a[N], ans[M], b[N], tail;
void check(int x) {
    for (int i = 1; i < tail; i ++) {
        if (x == b[i]) {
            tail = i;
            return;
        }
    }
}
void play_c(int x) {
    memset(b, 0, sizeof(b));
    tail = 1;
    for (int i = x; i <= n; i ++) {
        check(a[i]);
        b[tail] = a[i];
        tail ++;
    }
    for (int i = 1; i < tail; i ++) {
        ans[b[i]] ++;
    }
    return;
}
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i ++) {
        play_c(i);
    }
    for (int i = 1; i <= m; i ++) {
        cout << ans[i] << " ";
    }
    return 0;
}
