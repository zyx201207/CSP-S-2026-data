#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,k,u,v,dir,ans;
int d[N];
bool vis[N];
vector<int>e[N];
void dfs(int x,int fa){
    if(vis[x])d[x]=0;
    else d[x]=d[fa]+1;
    for(auto y:e[x]){
        if(y==fa)continue;
        dfs(y,x);
        d[x]=min(d[x],d[y]+1);
    }
    dir=max(dir,d[x]);
}
int cnt=0;
void check(int x,int fa){
    int cmp=0;
    for(auto y:e[x]){
        if(y==fa)continue;
        check(y,x);
        cmp+=vis[y];
    }
    if(cmp&&!vis[x])cnt+=cmp;
}
void f(int x,int m){
    if(x>n)return;
    if(m==k-1){
        vis[x]=1;
        int id=0;
        for(int i=1;i<=n;i++)if(!vis[i]){id=i;break;}
        cnt=0;
        check(id,0);
        if(cnt<=2){
            d[0]=2e9;
            dir=0;
            dfs(x,0);
            ans=min(ans,dir);
        }
        vis[x]=0;
        f(x+1,m);
    }
    vis[x]=1;
    f(x+1,m+1);
    vis[x]=0;
    f(x+1,m);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++){
            e[i].clear();
        }
        for(int i=1;i<=n-1;i++){
            scanf("%d%d",&u,&v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        ans=2e9;
        f(1,0);
        printf("%d\n",ans);
    }
    return 0;
}
