#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N = 2e5 + 5;
ull a[N];
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    if (m == 1) {
        cout << a[n];
    }
    else if (m == 2) {
        cout << a[n] & a[n - 1];
    }
    return 0;
}
//na you du gui tian tian shu.
//kao,zao zhi dao zuo wan zao dian shui le
//hao kun a
//?zen me zhi sheng 1h le
//suan le fan zheng shi csp-j
//guan zhu luogu static_summer & BOSD_winter xie xie miao.
