#include<bits/stdc++.h>
using namespace std;
const int N  = 510,M = 5e5+10;
int c,n,m,d,q;
int w[M];
int k[5];
int a[5][15];
int t[5][15];
int pos[5][15];
int e[15][25];
int vis[15][25];
int ans;
void dg(int x,int y,int s,int p,int o){
    if(x==y){
        ans = min(ans,s);
    }else{
        if(o==1){
            for(int i = 1;i<=e[x][0];i++){
                if(vis[e[x][i]][x]) continue;
                dg(x,y,s+t[e[x][i]][pos[e[x][i]][x]],e[x][i],0);
            }
        }else{
            for(int i = pos[p][x]+1;i<=k[p];i++){
                vis[p][a[p][i]] = 1;
                dg(a[p][i],y,s+t[p][i],p,1);
                vis[p][a[p][i]] = 0;
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i<=m;i++) cin >> w[i];
    if(c>=1&&c<=3){
        for(int i = 1;i<=n;i++){
            cin >> k[i];
            for(int j = 1;j<=k[i];j++){
                cin >> a[i][j] >> t[i][j];
                pos[i][a[i][j]] = j;
                e[a[i][j]][++e[a[i][j]][0]] = i;
            }
        }
        int x,y;
        for(int i = 1;i<=q;i++){
            cin >> x >> y;
            ans = 1e9+10;
            memset(vis,0,sizeof vis);
            dg(x,y,w[x]+w[y],0,1);
            cout << ans << "\n";
        }
    }else{
        
    }
    return 0;
}