#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+100;
int a[N];
char c[N];
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i] >> c[i];
    }
    int head = 1, tail = n;
    long long ans = 0;
    while (true) {
        if (a[head] < a[tail]) {
            a[tail] -= a[head];
            if (c[tail] != c[head]) ans += a[head];
            head ++;
        }
        else {
            a[head] -= a[tail];
            if (c[tail] != c[head]) ans += a[tail];
            tail --;
        }
        if (head == tail) break;
    }
    cout << ans << '\n';
    return 0;
}
