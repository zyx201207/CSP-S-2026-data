#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
long long x[2000006],out=0,ans=1e9,sol=1,vis[200006];
vector<long long> G[200006];
void addEdge(int u,int v){
    G[u].push_back(v);
}
void dfs(int s,int e,int step){
    if(s==e){
        if(step>ans){
            return;
        }
        else if(step==ans){
            sol++;
        }
        else if(step<ans){
            sol=1;
            ans=step;
        }
    }
    for(int k=0;k<G[s].size();k++){
        if(vis[G[s][k]]==0){
            vis[G[s][k]]=1;
            dfs(G[s][k],e,step+1);
            vis[G[s][k]]=0;
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<n;i++)
            for(int j=i+1;j<=n;j++)
                if(x[j]-x[i]<=d)
                    addEdge(i,j);
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                dfs(i,j,0);
                ans=1e9;
                memset(vis,0,sizeof(vis));
                if(sol==2){
                    out++;
                }
                sol=1;
            }
        }
        cout<<out<<endl;
        out=0;
        memset(G,0,sizeof(G));
    }
    return 0;
}
