#include<bits/stdc++.h>
#define N 1000005
using namespace std;
vector<int>G[N];
int vis[N],got[N],lst;
void dfs(int u){
    got[u]=1;
    for(int i=0;i<G[u].size();i++)if(vis[G[u][i]]&&!got[G[u][i]])dfs(G[u][i]);
    return;
}
void solve(int u,int Fa,int len){
    if(vis[u]){
        lst=min(lst,len);
        return;
    }
    for(int i=0;i<G[u].size();i++)if(G[u][i]!=Fa)solve(G[u][i],u,len+1);
    return;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,T;
    scanf("%d%d",&c,&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<n;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        if(c<=3){
            int ans=n;
            for(int op=1;op<(1<<n);op++){
                int u=op,cnt=0;
                while(u){
                    cnt++;
                    u-=(u&-u);
                }
                if(cnt>m)continue;
                for(int i=1;i<=n;i++)if(op&(1<<(i-1)))vis[i]=1;
                cnt=0;
                for(int i=1;i<=n;i++)if(vis[i]&&!got[i]){
                    cnt++;
                    dfs(i);
                }
                if(cnt>2){
                    for(int i=1;i<=n;i++)vis[i]=got[i]=0;
                    continue;
                }
                int res=0;
                for(int i=1;i<=n;i++)if(!vis[i]){
                    lst=n;
                    solve(i,i,0);
                    res=max(res,lst);
                }
                ans=min(ans,res);
                for(int i=1;i<=n;i++)vis[i]=got[i]=0;
            }
            printf("%d\n",ans);
            for(int i=1;i<=n;i++)G[i].clear();
        }
        if(c==13||c==14){
            if(n==m)printf("0\n");
            else if(m>=n/2)printf("1\n");
            else printf("%d\n",min((n/2-m+1)/2,(n/2-m+3)/4)+1);
        }
    }
    return 0;
}
//Igunareo ver.