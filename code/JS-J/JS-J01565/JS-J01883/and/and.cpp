#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, mx = -1, sum = 0;
const int N = 2e5+10;
int a[N];

void dfs(int now, int cnt) {
    if (cnt == m) {
        //cout << now << " " << cnt << " " << sum << " " << mx << endl;
        mx = max(mx, sum);
        sum = 0;
        return;
    }
    if (now > n) {
        return;
    }
    //cout << 1;
    int x = sum;
    if (cnt == 0) {
        sum = a[now];
    } else {
        sum = (sum & a[now]);
    }
    //cout << x;
    //cout << now << " " << cnt << " " << sum << " " << 1 << endl;
    dfs(now+1, cnt+1);
    sum = x;
    //cout << now << " " << cnt << " " << sum << " " << 0 << endl;
    dfs(now+1, cnt);
    //return;
}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (n <= 20) {
        dfs(1, 0);
        cout << mx;
    } else {
        cout << 1;
    }

    return 0;
}
