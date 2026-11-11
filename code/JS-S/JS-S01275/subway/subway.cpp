#include<bits/stdc++.h>
using namespace std;
long long c,m,n,d,q;
int w[10005];
long long step[500][20005];
int k[505];
bool vis[505];

set<int> se[20005];

int dfs(int x,int y){
    vis[x]=1;
    long long minidis=INT_MAX;
    for(auto i=se[x].begin();i!=se[x].end();i++){
        if(step[*i][y]){
            minidis=min(minidis,step[*i][y]+step[*i][x]);
        }
        else{
            for(int j=1;j<=n;j++){
                if(!vis[j]&&step[*i][j])minidis=min(minidis,step[*i][j]+step[*i][x]+dfs(j,y));
            }
        }
    }
    vis[x]=0;
    return minidis;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }

    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1,a,t;j<=k[i];j++){
            cin>>a>>t;
            step[i][a]=t;
            se[a].insert(i);
        }
    }
    for(int T=1;T<=q;T++){
        int x,y;
        cin>>x>>y;
        int ans=w[x]+w[y];
        cout<<ans+dfs(x,y);
    }
}
