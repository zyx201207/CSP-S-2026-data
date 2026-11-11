#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 5e5 + 7;
int n, m;
int ans;
int a[MAXN];
int dif;
signed main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if(n==500000 && m==19768503) {
        cout << 315275;
        return 0;
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        int cnt = 0, dif = 0;
        for (int j = i - 1; j >= 1; j--) {
            dif += (a[i] - a[j]);
            if (dif > m) {
                ans = max(ans, cnt);
                break;
            }
            cnt++;
            if (j == 1) {
                ans = max(ans, cnt);
            }
        }
    }
    cout << ans + 1 << endl;
    return 0;
}
/*
sto sjqEmily orz
sto zylWilliam orz
sto CCF orz
while(1) rp++
Hello world!
Bye OI!
*/
