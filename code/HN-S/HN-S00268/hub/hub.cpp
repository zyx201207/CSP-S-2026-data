#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
vector<int >g[2000006];
int dis[2000006];
int f[2][2][2000006],mad[2][2000006],man[2][2000006];
int d;
void dfs1(int x,int fa){
    for(auto y:g[x]){
        if(y!=fa){
            dis[y]=dis[x]+1;
            dfs(y,x);
        }
    }return ;
}void dfs(int x,int fa){
    
}




















bool chk(int x){
    d=x;
    dfs(1,0);
    if(min(min(f[0][0][1]+(man[0][0][1]>0),f[0][1][1]+(man[0][1][1]>0)),min(f[1][0][1],f[1][1][1]))<=k)return 1;
    return 0
}














int main(){
    // freopen("hub.in","r",stdin);
    // freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            g[i].clear();
        }for(int i=1;i<n;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(v);
        }dfs1(1,0);
        if(n==k){
            printf("0\n");
        }else {
            int ans=0;
            for(int i=1<<20;i>=1;i/=2){
                if(!chk(ans+i))ans+=i;
            }printf("%d\n",ans+1);
        }
    }
    return 0;
}