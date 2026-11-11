#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=550;
const int M=5e5+50;
int c,n,m,d,Q;
ll w[M];
struct node{
    int id;
    ll ww;
};
vector<node>p[M];
int k[N];
int tmpa;
ll tmpt;
int cnt;
int cntu,cntv;
int u,v;
ll f[N][N];
ll ans;
ll yseinf;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>Q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>tmpa;
            cin>>tmpt;
            p[tmpa].push_back(node{i,tmpt});
        }
    }
    memset(f,0x3f,sizeof f);
    yseinf=f[0][0];
    for(int i=1;i<=n;i++) f[i][i]=0ll;
    for(int i=1;i<=m;i++){
        cnt=(int)(p[i].size());
        for(int x=0;x<cnt;x++){
            for(int y=0;y<cnt;y++){
                if(x==y) continue;
                f[p[i][x].id][p[i][y].id]=min(f[p[i][x].id][p[i][y].id],p[i][x].ww+p[i][y].ww);
                f[p[i][y].id][p[i][x].id]=min(f[p[i][y].id][p[i][x].id],p[i][x].ww+p[i][y].ww);
            }
        }
    }
    for(int x=1;x<=n;x++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f[i][j]=min(f[i][j],f[i][x]+f[x][j]);
            }
        }
    }
    while(Q--){
        cin>>u>>v;
        cntu=(int)(p[u].size());
        cntv=(int)(p[v].size());
        ans=yseinf;
        for(int i=0;i<cntu;i++){
            for(int j=0;j<cntv;j++){
                ans=min(ans,f[p[u][i].id][p[v][j].id]+p[u][i].ww+p[v][j].ww);
            }
        }
        ans+=w[u];
        ans+=w[v];
        cout<<ans<<'\n';
    }
    return 0;
}