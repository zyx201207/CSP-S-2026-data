#include<bits/stdc++.h>
using namespace std;
long long n, ans;
long long m;
long long a[500010];
long long b[500010];
long long c[500010];
long long qzh[500010];
vector<int> cha[500010];
vector<int> qzh2[500010];
bool flag1 = 1;
bool flag2 = 1;
bool check(long long x) {
    //cout << b[4 + 2 - 1] - b[4] - c[4 + 2 - 1] * (4 - 1) << '\n';
    for (int i = 1; i <= n - x; i++) {
        if (n <= 5000) {
            long long tot = 0;
            //if (flag1 || flag2) {
            //    tot = b[i + x - 1] - b[i];
            //}
            for (int j = i; j < i + x; j++) {
                tot += a[i + x - 1] - a[j];
            }
            //cout << tot << '\n';
            if (tot <= m) return 1;
        } else {
            if (b[i + x - 1] - b[i] - c[i] * (i - 1)<= m) { // <- i dont know why, selftest wrong at 4th
                //cout << b[i + x - 1] << " " <<  b[i] << " " << c[i + x - 1] * (i - x + 1) << " ";
                //cout << '\n';
                //cout << b[i + x - 1] - b[i] - (qzh[i + x - 1] - qzh[i]) << " ";
                //cout << b[i + x - 1] - b[i] - qzh2[i];
                return 1;
            }
        }

    }
    //cout << '\n';
    return 0;
}
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        //if (a[i] != i) flag1 = 0;
    }
    //int asdf = a[2] - a[1];
    //for (int i = 2; i <= n; i++) {
    //    if (a[i - 1] - a[i] != asdf) {
    //        flag2 = 0;
    //        break;
    //    }
    //}
    sort(a + 1, a + 1 + n);
    for (int i = 2; i <= n; i++) {
        b[i] = b[i - 1] + (a[i] - a[i - 1]) * (i - 1);
        c[i] = a[i] - a[i - 1];
        //cout << b[i] << " " << c[i] << '\n';
    }
    /*for (int i = 1; i <= n; i++) {
        cha[i].resize(n + 1, 0);
        for (int j = i; j <= n; j++) {
            cha[i][j] = a[j] - a[i];
            cout << cha[i][j] << " ";
        }
        cout << '\n';
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << cha[i][j] << " ";
        }
        cout << '\n';
    }*/
    //cout << b[4 + 2 - 1] - b[4] - qzh2[4];
    //for (int i = 2; i <= n; i++) {
    //    qzh[i] = qzh[i - 1] + (i - 2) * c[i];
        //cout << qzh[i] << " ";
    //}
    //cout << '\n';
    //cout << b[4 + 2 - 1] << " " <<  b[4] << " " << c[5] * (4 + 2 - 2) << " ";
    int l = 1, r = n + 1;
    //cout << check(315275);
    while (l < r) {
        long long mid = l + r >> 1;
        if (check(mid)) {
            ans = max(ans, mid);
            //cout << mid << " ";
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    //cout << '\n';
    cout << ans;
    return 0;
}
// fail 100 -> 45
// just a small wrong /ll
// er fen + hua dong chaung kou
// **** ***
// why so hard
// afo 2026-10-31
