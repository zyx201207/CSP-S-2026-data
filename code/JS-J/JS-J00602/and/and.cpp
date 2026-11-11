#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int n, m, maxx = -1;
long long alland, ans = -1;
int a[N], b[N];
bool use[N];
int binsub[40] = {0, 1, 3, 7, 15, 31, 63, 127, 255, 511, 1023, 2047, 4095, 8191, 16383, 32767, 65535, 131071, 262143, 524287, 1048575, 2097151, 4194303, 8388607, 16777215, 33554431, 67108863, 134217727, 268435455, 536870911, 1073741823, 2147483647};
bool outflag = true;

void dfs(int cnt, int r) {
    if (cnt == r) {
        long long t = b[1];
        for (int i = 1; i <= r; i++) t &= b[i];
        ans = max(ans, t);
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!use[i]) {
            use[i] = true;
            b[cnt] = a[i];
            dfs(cnt + 1, r);
            dfs(cnt, r);
            use[i] = false;
            b[cnt] = 0;
        }
    }
}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i == 1) alland = a[i];
        maxx = max(maxx, a[i]);
        alland &= a[i];
        bool inflag = false;
        for (int j = 0; j <= 31; j++) {
            if (a[i] == binsub[j]) {
                inflag = true;
                break;
            }
        }
        outflag &= inflag;
    }
    if (m == 1) {
        cout << maxx;
        return 0;
    }
    if (m == n) {
        cout << alland;
        return 0;
    }
    if (outflag) {
        cout << maxx;
        return 0;
    }
    dfs(0, m);
    cout << ans;

    return 0;
}
