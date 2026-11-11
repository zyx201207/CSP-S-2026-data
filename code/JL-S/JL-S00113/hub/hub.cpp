#include<bits/stdc++.h>
using namespace std;
const int N=2e6+1;
int c,t,n,u,v,dis[N];
vector<int>G[N];
void dfs(int u,int fa){
    dis[u]=dis[fa]+1;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v!=fa) dfs(v,u);
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        for(int i=1;i<=n;i++) G[i].clear();
        cin>>n;
        for(int i=1;i<n;i++){
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(1,0);
        int maxn=0,maxi=0;
        for(int i=1;i<=n;i++){
            if(dis[i]>maxn){
                maxn=dis[i];
                maxi=i;
            }
        }
        dfs(maxi,0);
        maxn=0;
        for(int i=1;i<=n;i++){
            if(dis[i]>maxn){
                maxn=dis[i];
            }
        }
        cout<<(maxn-1)/2<<endl;
    }
}
