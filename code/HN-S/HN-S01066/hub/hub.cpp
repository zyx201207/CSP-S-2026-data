#include<bits/stdc++.h>
using namespace std;
//#define int long long
int n,k;
vector<int> g[1000005];/*
int f[4005][4005][4];
void dfs(int u,int fa){
    f[u][0][0]=0;
    f[u][1][0]=0;
    int iv;
    for(auto v:g[u])if(v!=fa){
        dfs(v,u);
        if(f[v][0][0]+1>f[u][0][0]) iv=v;
        f[u][0][0]=max(f[u][0][0],f[v][0][0]+1);


        for(int i=k;i>=1;i--){
                int ff=0x7fffffff;
        for(int j=1;j<=i;j++)
        ff=min(ff,max(f[u][j][0],f[v][i-j][0]+(i==j)));
        f[u][i][0]=ff;
        }
    }
    for(auto v:g[u])if(v!=fa){
        if(v!=iv){
            for(int i=1;i<=k;i++) f[u][i][1]=max(f[u][i][1],f[v][0][0]+1);
        }
    }
}*/
int ans1,ansd;
void dfs1(int u,int fa,int dep){
    if(dep>ansd){
        ans1=u,ansd=dep;
    }
    for(auto v:g[u])if(v!=fa){
        dfs1(v,u,dep+1);
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<n;i++){
            int u,v;cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        ansd=0;
        dfs1(1,1,0);
        ansd=0;
        dfs1(ans1,ans1,0);
        cout<<max(0.0l,ceil((long double)(ansd-k)/(long double)(k+1)))<<'\n';
    }

    return 0;
}/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
