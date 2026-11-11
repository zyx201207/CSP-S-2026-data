
#include<bits/stdc++.h>
#define ll long long

using namespace std;
int c,T;
int n,k;
vector<int> G[200010];
int p[200010],f[200010],vis[200010],dep[200010];
int ans=1e9;
void build(int u,int fa){
    if(vis[u])return ;
    vis[u]=1;
    dep[u]=dep[fa]+1;
    f[u]=fa;
    for(int v:G[u])build(v,u);
    return ;
}
int way(int x,int y){
    int sum=0;
    if(dep[x]<dep[y])swap(x,y);
    while(dep[x]==dep[y]){
        x=f[x];
        sum++;
    }
    while(x==y){
        x=f[x],y=f[y];
        sum+=2;
    }
    return sum;

}
void plt(int x){
    if(vis[x]||!p[x])return ;
    vis[x]=1;
    for(int v:G[x])plt(v);
    return ;
}
void dfs(int x,int step){
    if(x>n){
        int cnt=0;
        for(int i=1;i<=n;i++)vis[i]=0;
        for(int i=1;i<=n;i++){
            if(p[i]&&!vis[i]){
                cnt++;
                plt(i);
            }
        }
        if(cnt>2)return ;
        int mx=0;
        for(int i=1;i<=n;i++){
            if(p[i])continue;
            for(int j=1;j<=n;j++){
                if(i==j)continue;
                mx=max(mx,way(i,j));
            }
        }
        ans=min(ans,mx);
        return ;
    }
    if(step>k)return ;
    p[x]=0;
    dfs(x+1,step);
    p[x]=1;
    dfs(x+1,step+1);
    return ;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            int a,b;
            cin>>a>>b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        build(1,0);
        dfs(1,0);
        cout<<ans<<'\n';
        for(int i=1;i<=n;i++){
            dep[i]=f[i]=vis[i]=p[i]=0;
            G[i].clear();
        }
        ans=1e9;
    }
    return 0;
}
//Oct31==Dec25?
