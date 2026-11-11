#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 500010;

int n,m;
int a[MAXN];

void read() {
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
}

void solve(){
    sort(a+1,a+1+n);
    int l = 1,r = 1;
    int ans = 1;
    int consumed = 0;
    while(r<n) {
        r++;
        int len = r-l;
        int delta = a[r]-a[r-1];
        int cost = len * delta;
        while( consumed + cost > m ){
            consumed -= a[r-1]-a[l];
            cost -= a[r]-a[r-1];
            l++;
            len--;
        }
        consumed += cost;
        ans = max(ans, len+1);
    }
    cout << ans;
}

signed main(){
    freopen( "crystal.in", "r", stdin );
    freopen( "crystal.out", "w", stdout );
    int T = 1;
    while( T-- ) {
        read();
        solve();
    }
    return 0;
}