#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M=500010;
const int N=505;
ll c,m,n,d,q,w[M],a[N][M],t[N][M],k[N];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> m >> n >> d >> q;
    for(int i = 1; i <= m; i++){
        cin >> w[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> k[i];
        for(int j = 1; j <= k[i]; j++) {
            cin >> a[i][j] >> t[i][j];
        }
    }
    ll x,y;
    while(q--){
        cin >> x >> y;

    }
    return 0;
}
