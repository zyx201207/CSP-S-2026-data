#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N = 2e5 + 5;
ull len;
ull n, a;
string s;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> a >> c;
        len += a;
        for (int j = 1; j <= a; j++) {
            s += c;
        }
    }
    int mid = len / 2;
    ull ans = 0;
    for (int i = 0; i < mid; i++) {
        if (s[i] != s[len - 1- i]) {
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}
// a[i] <= 1e9 shi hyw.
//zheng jie mei kan chu lai zen me xie, wo shi qv
//zhi neng da bao li le QAQ
//luogu:static_summer
/*
jiu yi tong sheng kai ba
jiu yi tong diao luo ba
za luan de fu shu pin
ci ke ye wu yi yi
jin zhao hui qv xiang na
ming tian hui liu luo na
ru hua ban shi qv de
he tong hua fan pian de
*/
