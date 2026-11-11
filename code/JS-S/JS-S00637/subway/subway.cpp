#include<bits/stdc++.h>

#define pcn putchar('\n');
#define pck putchar(' ');
#define int long long

using namespace std;
const int mod=998244353;

void free(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
}

int c,n,m,d,q;
int w[500010];
struct wzy{
    int id,t;
    wzy(int _id,int _t){
        id=_id;
        t=_t;
    }
};
vector<wzy> g[500010];
int f[510][510];
signed main(){
    //scanf("%d",);
    //printf("%d",);
    free();
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
    for(int i=1;i<=n;i++){
        int k;
        scanf("%lld",&k);
        for(int j=1;j<=k;j++){
            int a,t;
            scanf("%lld%lld",&a,&t);
            g[a].push_back(wzy(i,t));

        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f[i][j]=0x3f3f3f3f3f;
        }
    }
    for(int i=1;i<=n;i++) f[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<g[i].size();j++){
            for(int k=j+1;k<g[i].size();k++){
                if(k>=g[i].size()) continue;
                f[g[i][j].id][g[i][k].id]=f[g[i][k].id][g[i][j].id]=min(f[g[i][j].id][g[i][k].id],g[i][j].t+g[i][k].t);
            }
        }
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int u,v;
        cin>>u>>v;
        int ans=w[u]+w[v]+g[u][0].t+g[v][0].t+f[g[u][0].id][g[v][0].id];
        for(int i=0;i<g[u].size();i++){
            for(int j=0;j<g[v].size();j++){
                ans=min(ans,w[u]+w[v]+g[u][i].t+g[v][j].t+f[g[u][i].id][g[v][j].id]);
            }
        }
        cout<<ans;
        pcn;
    }
    return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2




*/

