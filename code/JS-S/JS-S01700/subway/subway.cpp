#include<bits/stdc++.h>
#define int long long
using namespace std;
struct N{
    int s,t;
};
int p[505][505];
int tsf[505][505];
int cc,t,n,m,d,q;
int w[500050];
vector<N> a[505];
vector<N> b[500050];
vector<int> c[505];
int vis[505];
int ans=1e18;
void dfs(int l,int sm,int tm){
    vis[l]=1;
    for(int i=0;i<b[tm].size();i++){
        if(l==b[tm][i].s){
            sm+=b[tm][i].t;
            ans=min(ans,sm);
            return;
        }
    }
    for(int i=0;i<c[l].size();i++){
        if(vis[c[l][i]]==1){
            continue;
        }
        dfs(c[l][i],sm+p[l][c[l][i]],tm);
    }
    vis[l]=0;
    return ;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>cc>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int aa,tt;
            cin>>aa>>tt;
            a[i].push_back({aa,tt});
            b[aa].push_back({i,tt});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            p[i][j]=1e18;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<b[i].size()-1;j++){
            for(int k=j+1;k<b[i].size();k++){
                int ln1=b[i][j].s,ln2=b[i][k].s;
                int t1=b[i][j].t,t2=b[i][k].t;
                tsf[ln1][ln2]=1;
                tsf[ln2][ln1]=1;
                p[ln1][ln2]=min(p[ln1][ln2],t1+t2);
                p[ln2][ln1]=p[ln1][ln2];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(tsf[i][j]=1){
                c[i].push_back(j);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        ans=1e18;
        memset(vis,0,sizeof vis);
        for(int i=0;i<b[x].size();i++){
            dfs(b[x][i].s,w[x]+w[y]+b[x][i].t,y);
        }
        cout<<ans<<'\n';
    }
    return 0;
}

