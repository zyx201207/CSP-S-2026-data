#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+5;
int c,n,m,d,q;
int w[MAXN];
vector<int> belong[MAXN];
int t[MAXN][505];
int f[505][505];
void floyd(){
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    return;
}
int solve(int x,int y){
    int ret=0x7fffffff;
    for(auto&u:belong[x])
        for(auto&v:belong[y])
            ret=min(ret,f[u][v]+t[x][u]+t[y][v]);
    return ret+w[x]+w[y];
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        while(k--){
            int a,b;cin>>a>>b;
            belong[a].push_back(i);
            t[a][i]=b;
        }
    }
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++) f[i][i]=0;
    for(int i=1;i<=m;i++)
        for(auto&u:belong[i])
            for(auto&v:belong[i]){
                if(u==v) continue;
                f[u][v]=f[v][u]=t[i][u]+t[i][v];
            }
    floyd();
    while(q--){
        int x,y;cin>>x>>y;
        cout<<solve(x,y)<<'\n';
    }
    return 0;
}
