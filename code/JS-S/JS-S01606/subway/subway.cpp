#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5 * 114514;
const int M = 514;
int c,n,m,d,q;
int w[N];
vector<pair<int,int> > g[M];
vector<pair<int,int> > g2[N];
int ds[M][M];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i ++ ){
        cin >> w[i];
    }
    for(int i = 1;i <= n;i ++ ){
        int ss;
        cin>>ss;
        while(ss--){
            int aa,tt;
            cin >> aa >> tt;
            g[i].push_back({aa,tt});
            g2[aa].push_back({i,tt});
        }
    }
    memset(ds,0x3f,sizeof ds);
    for(int i=1;i<=n;i++) ds[i][i] = 0;
    for(int i = 1;i <= n;i ++ ){
        for(auto y : g[i]){
            int t1 = y.first;
            int w1 = y.second;
            for(auto z : g2[t1]){
                int w2 = z.second;
                int t2 = z.first;
                ds[i][t2] = min(ds[i][t2],w1 + w2);
                ds[t2][i] = min(ds[t2][i],w1 + w2);
                // cout << i << " " << w1 << "  " << t2 << " " << w2 << endl;
            }
        }
    }
    /*
    for(int i = 1;i <= n;i ++ ){
        for(int j = 1;j <= n;j ++ ){
            cout << i << " " << j << " : " << ds[i][j] << endl;
        }
    }
    */
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            for(int k = 1;k <= n;k ++ ){
                if(i == k || j == k) continue;
                ds[i][j] = min(ds[i][j],ds[i][k] + ds[k][j]);
            }
        }
    }
    /*
    for(int i = 1;i <= n;i ++ ){
        for(int j = 1;j <= n;j ++ ){
            cout << i << " " << j << " " << ds[i][j] << endl;
        }
    }
    */
    while(q--){
        int xx,yy;
        cin>>xx>>yy;
        int res = LONG_LONG_MAX - INT_MAX;
        for(auto y : g2[xx]){
            int t0 = y.first,ww = y.second;
            for(auto z : g2[yy]){
                int t1 = z.first,www = z.second;
                // cout << xx << " " << t0 << " " << ww << "  " << yy << " " << t1 << " " << www << "  " << ds[t0][t1] << endl;
                res = min(res,www + ww + ds[t0][t1]);
            }
        }
        int ans = res + w[xx] + w[yy];
        cout << ans << endl;
    }
    return 0;
}