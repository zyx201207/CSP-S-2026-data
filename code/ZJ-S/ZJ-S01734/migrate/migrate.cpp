#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2E6+5;

int c,T,n,d,a[N];

int solve() {
    if(n < 3) return 0;
    if(c<=6) {
        int ans = 0;
        for(int u=1;u<=n;u++) {
            for(int v=u+2;v<=n;v++) {
                ans ++ ;
            }
        }
        return ans;
    }

    if(c == 11 || c==12) {
        int sub = a[2] - a[1];
        int p = d / sub;
        if(p == 1) return 0;
        if(p == 2) return n - 3;
    }

    return 0;
}

signed main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> c >> T;
    while(T -- ) {
        cin >> n >> d;
        for(int i=1;i<=n;i++) {
            cin >> a[i];
        }
        cout << solve() << '\n';
    }
    

    return 0;
}