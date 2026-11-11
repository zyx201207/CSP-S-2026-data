#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005];
struct node{
    long long u;
    long long w;
};
node station[500005][21];
long long mp[501][501];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)mp[i][j]=0;
            else mp[i][j]=4e18;
        }
    }
    for(int i=1;i<=m;i++){
        cin >> w[i];
        station[i][0].w=0;
    }
    for(int i=1;i<=n;i++){
        long long k;
        cin >> k;
        for(int j=1;j<=k;j++){
            long long a;
            long long x;
            cin >> a >> x;
            for(int p=1;p<=station[a][0].w;p++){
                node v=station[a][p];
                mp[i][v.u]=mp[v.u][i]=min(mp[v.u][i],x+v.w);
            }
            station[a][++station[a][0].w]=(node){i,x};
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                mp[j][i]=mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
            }
        }
    }
    while(q--){
        long long x,y;
        long long res=4e18;
        cin >> x >> y;
        for(int i=1;i<=station[x][0].w;i++){
            node u=station[x][i];
            for(int j=1;j<=station[y][0].w;j++){
                node v=station[y][j];
                res=min(res,w[x]+w[y]+u.w+v.w+mp[u.u][v.u]);
            }
        }
        cout << res << "\n";
    }
    return 0;
}
