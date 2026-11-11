#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500005];
vector<int> a[505],t[505];
void solve(){
    int st,ed;
    cin >> st >> ed;
   cout << w[st]+w[ed]+t[st][0]+t[ed][0] << endl;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++)cin >> w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin >> k;
        int x,y;
        for(int j=0;j<k;j++){
            cin >> x >> y;
            a[i].push_back(x);
            t[i].push_back(y);
        }
    }
    while(q--){
        solve();
    }
    return 0;
}
