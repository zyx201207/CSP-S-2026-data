#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 7;
//long long 1^12

ll a[N];
ll pre[N];
ll n, m;

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    bool flag = false;
    pre[1] = a[1];
    for (int i = 2; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
        if (a[i] - a[i - 1] <= m) flag = true;
    }
    if (!flag) {
        cout << 1;
        return 0;
    }
    ll maxx = 1; //teli
    for (int i = n; i >= 1; i--) {
        int pos = i - maxx - 1;
        if (pos < 1) break;
        while (pos >= 1) {
            if ((maxx + 1) * a[i] - (pre[i - 1] - pre[pos - 1]) <= m) {
                maxx++;
                pos--;
            } else break;
        }
    }
    cout << maxx + 1;




    return 0;
}
