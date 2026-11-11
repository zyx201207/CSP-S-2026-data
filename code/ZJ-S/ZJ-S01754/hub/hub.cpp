#include<bits/stdc++.h>
using namespace std;
int c,T,vis[15],k,n,kuai=0,dis,ans=INT_MAX;
vector<int> t[15];
int dfs1(int x,int fa){
    if(!vis[fa]&&vis[x]){
        kuai++;
    }
    int ld=0x3f3f3f;
    if(vis[x])ld=0;
    for(auto it:t[x]){
        if(it==fa)continue;
        ld=min(ld,dfs1(it,x)+1);
    }
    return ld;
}
void dfs(int x,int l){
    if(x>k){
        dis=0;
        kuai=0;
        dis=max(dis,dfs1(1,0));
        if(kuai<=2){
            for(int i=2;i<=n;i++){
                if(!vis[i]){
                    dis=max(dis,dfs1(i,0));
                }
            }
            ans=min(ans,dis);
        }
        return;
    }
    if(l>n)return;
    vis[l]=1;
    dfs(x+1,l+1);
    vis[l]=0;
    dfs(x,l+1);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    if(c<=3){
        while(T--){
            ans=INT_MAX;
            cin>>n>>k;
            for(int i=1;i<=n;i++)t[i].clear();
            for(int i=1;i<n;i++){
                int u,v;
                cin>>u>>v;
                t[u].push_back(v);
                t[v].push_back(u);
            }
            dfs(1,1);
            cout<<ans<<'\n';    
        }
        
    }
}