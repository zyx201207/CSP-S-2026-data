#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k;
struct railway{
    int a,t,f;
};
railway r[505][100005];
int vis[505][500005];
int ans(int s,int e){
    int ns = 2e9;
    int i=1,j=1;
    while(i<=n && j<=n){
        if(r[i][s].f==0)    i++;
        if(r[j][e].f==0)    j++;
        if(r[i][s].f==1&&r[j][e].f==1){
            if(i==j){
                int na = w[s]+w[e]+r[i][s].t+r[j][e].t;
                ns = min(ns,na);
            }
        }
    }
    return ns;
}
int main(){
    //freopen("subway.in","r",stdin);
    //freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++){
        cin >> w[i];
    }
    for(int i = 1;i <= n;i++){
        int k;
        cin >> k;
        for(int j = 1;j <= k;j++){
            cin >> r[i][j].a >> r[i][j].t;
            r[i][j].f = 1;
        }
    }
    while(q--){
        int x,y;
        cin >> x >> y;
        cout << ans(x,y) << endl;
    }
    return 0;
}

