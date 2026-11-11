#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;
ll n, m, ans;
ll cnt, num;
ll a[N], b[N], c[N];
bool ok;

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;++i) {
        cin >> a[i];
    }
    for(int i = 29;i >= 0;--i) {
        if(!ok) {
            num = 0;
            for(int j = 1;j <= n;++j) {
                if((a[j] >> i) & 1) {
                    b[++num] = a[j];
                }
            }
            if(num < m) continue;
            ok = 1;
            cnt = num;
            ans += (1 << i);
        } else {
            num = 0;
            for(int j = 1;j <= cnt;++j) {
                if((b[j] >> i) & 1) {
                    c[++num] = b[j];
                }
            }
            if(num < m) continue;
            cnt = num;
            for(int j = 1;j <= cnt;++j) {
                b[j] = c[j];
            }
            ans += (1 << i);
        }
    }
    if(!ok) {
        cout << 0;
    } else {
        cout << ans;
    }
    return 0;
}
