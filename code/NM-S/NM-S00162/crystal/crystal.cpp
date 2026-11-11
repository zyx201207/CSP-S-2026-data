#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

using ll = long long;
ll n, m, lvln, ans;
ll a[N], c[N];
bool isA = 1, isB = 1;

struct level {
    ll n;
    ll num;
}lvl[N];

int count_c(int c[], int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++){
        c[i] = c[i-1] + a[i];
        sum += c[i];
    }
    return sum;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    ll p = a[2] - a[1];
    for (ll i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i] != i) isA = 0;
        if (a[i] - a[i-1] != p) isB = 0;
    }
    if (isA) {
        for (int i = n; i >= 1 && m >= 0; i--) {
            m -= -(i - n) + 1;
            ans++;
        }
        cout << ans;
        return 0;
    } else if (isB){
        for (int i = n; i >= 1 && m >= 0; i--) {
            m -= (-(i - n) + 1) * p;
            ans++;
        }
        cout << ans;
    } else {
    //    for (ll i = 1; i <= n; i++) {
    //        cout << a[i] << ' ';
    //    } cout << endl;
        for (int i = 1; i <= n; i++) {
            ll tempAns = 0;
            for (int j = i-1; j >= 1; j--) {
                ll temp = m;
                if (temp - abs(a[i] - a[j]) >= 0) temp -= abs(a[i] - a[j]);
                else break;
                if (temp == 0) break;
                tempAns++;
                // cout << temp << ' ';
            }
            ans = max(tempAns, ans);
        }
        cout << ans;
        return 0;
    }

    lvl[0].n = 0x3f3f3f3f;
    for (ll i = 1; i <= n; i++) {
        if (a[i] != a[i-1]) {
            lvln++;
            lvl[lvln].n = a[i];
            lvl[lvln].num++;
        } else lvl[lvln].num++;
    }

    for (int i = 1; i <= lvln; i++){
        cout << lvl[i].n << ' ' << lvl[i].num << endl;
    }

    for (int i = 1; i <= lvln; i++) {
        ll tmp_ans = lvl[i].num;
        for (int j = i-1; j >= 1; j--) {
            ll temp = m;
            if (temp - (lvl[i].n - lvl[j].n) * lvl[j].num > 0) {
                tmp_ans += lvl[j].num;
                temp -= (lvl[i].n - lvl[j].n) * lvl[j].num;
            } else if (temp - (lvl[i].n - lvl[j].n) * lvl[j].num == 0) {
                tmp_ans += lvl[j].num;
                temp -= (lvl[i].n - lvl[j].n) * lvl[j].num;
                break;
            }else {
                tmp_ans += temp / (lvl[i].n - lvl[j].n);
                break;
            }
            // cout << temp << '\n';
        }
        // if (tmp_ans == 3845) cout << tmp_ans << endl;
        ans = max(ans, tmp_ans);
    }
    cout << ans;
    return 0;
}
