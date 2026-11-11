#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e5 + 5;

int n;
ll m, a[N], pre[N];

bool Can (int x, int y) {
    long long tmp = pre[y] - pre[x - 1];
    tmp = a[y] * (y - x + 1) - tmp;
    if(tmp <= m) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i ++) {
        pre[i] = pre[i - 1] + a[i];
    }
    int idx = 1, ans = 0;
    for (int i = 1; i <= n; i ++) {
        while(!Can(idx, i) && idx <= i) {
            idx ++;
        }
        ans = max(ans, i - idx + 1);
    }
    cout << ans;
    return 0;
}