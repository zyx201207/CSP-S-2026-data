#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int c, t;
int n, d;
int x[N];
int f[N];
int ans;
map <pair<int, int>, int> book;
void calc(int a, int b) {
    if (book[{a, b}])
        return;
    book[{a, b}] = 1;
    if (x[a] + d > x[b])
        return;
    int cur = 0;
    int cnt = 0x3f3f3f3f, cnt1 = 0;
    for (int i = b - 1; x[i] + d > x[b] && i > a; i--) {
        calc(a, i);
        cur = book[{a, i}] + 1;
        if (cur == cnt)
            cnt1++;
        else if (cur < cnt)
            cnt1 = 0;
        cnt = min(cnt, cur);
    }
    if (cnt1 == 2)
        ans++;
    book[{a, b}] = cnt;
    return;
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--) {
        book.clear();
        ans = 0;
        cin >> n >> d;
        for (int i = 1; i <= n; i++)
            cin >> x[i];
        for (int i = 1; i < n; i++)
            for (int j = i + 1; j <= n; j++)
                calc(i, j);
        cout << ans << endl;
    }
    return 0;
}
