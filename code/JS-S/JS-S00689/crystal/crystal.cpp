#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int N = 500007;

int n, m;
int a[N], dif[N], pre[N];

void spec(int x) {
    int sum = a[n] - a[1];
    if (sum <= m) {
        cout << n << endl;
    }
    int cnt = 1;
    for (int i = n; i >= 1; i--) {
        sum -= x * cnt;
        if (sum <= m) {
            cout << i << endl;
        }
        cnt++;
    }
}

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int flg = 1, df;
    for (int i = 1; i <= n; i++) {
        dif[i] = a[i] - a[i - 1];
        if (i == 2) df = dif[i];
        else {
            if (df != dif[i]) flg = 0;
        }
    }
    if (flg == 1) {
        spec(df);
        return 0;
    }
    int tt = 0;
    for (int i = 2; i <= n; i++) {
        tt += dif[i] * (i - 1);
    }
    if (tt <= m) {
        cout << n << endl;
        return 0;
    }
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= n - i + 1; j++) {
            int tot = 0, cnt = 1;
            for (int k = j + 1; k <= j + i - 1; k++) {
                tot += dif[k] * cnt;
                cnt++;
            }
            if (tot <= m) {
                cout << i << endl;
                return 0;
            }
        }
    }






    return 0;
}


/*

15
-8 -3 6 7 9 23


*/
