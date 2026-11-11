#include<bits/stdc++.h>
using namespace std;
int vis[500005];
int w[500005];
int x,y;
vector<pair<int,int>> g[500005];
void dfs(int u,int val){
    vis[u]=1;
    if(u==y){
        cout<<val<<endl;
        return;
    }
    for(auto v:g[u]){
        int sum=val+v.second;
        if(!vis[v.first])
            dfs(v.first,sum);
    }
}


int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    int a[505][2005],t[505][2005],k[505];
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
            cin>>a[i][j]>>t[i][j];
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=k[i];j++)
            for(int l=1;l<=k[i];l++)
                if(j!=l){
                    int val=w[i]+t[i][j];
                    g[j].push_back({l,val});
                }

    while(q--){
        cin>>x>>y;
        for(int i=1;i<=m+5;i++)
            vis[i]=0;
        dfs(x,0);
    }
}
