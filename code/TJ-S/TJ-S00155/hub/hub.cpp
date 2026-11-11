#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
vector<int>G[maxn];
void solve(){

}
int tg=0,vis=0;
void dfs1(int u,int fa){
    if((tg>>(u-1))&1)vis|=(1<<(u-1));
    else return;
    for(int i=0,v=0;i<G[u].size();i++){
        v=G[u][i];
        if(v==fa)continue;
        dfs1(v,u);
    }
}
int dis[maxn];
void dfs2(int u,int fa,int d){
    dis[u]=min(dis[u],d);
    for(int i=0,v=0;i<G[u].size();i++){
        v=G[u][i];
        if(v==fa)continue;
        dfs2(v,u,d+1);
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    if(c==13||c==14){
        while(t--){
            solve();
        }
        return 0;
    }
    while(t--){
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)G[i].clear();
        for(int i=1;i<n;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        int res=0x3f3f3f3f;
        for(tg=0;tg<(1<<n);tg++){
            if(__builtin_popcount(tg)==k){
                vis=0;
                int cnt=0;
                for(int i=1;i<=n;i++){
                    if(!((tg>>(i-1))&1))continue;
                    if((vis>>(i-1))&1)continue;
                    dfs1(i,0);
                    cnt++;
                }
                // cout<<cnt<<'\n';
                if(cnt>2)continue;
                for(int i=1;i<=n;i++)dis[i]=0x3f3f3f3f;
                for(int i=1;i<=n;i++){
                    if((tg>>(i-1))&1){
                        dfs2(i,0,0);
                    }
                }
                int maxd=0;
                for(int i=1;i<=n;i++)maxd=max(maxd,dis[i]);
                res=min(res,maxd);
            }
        }
        printf("%d\n",res);
    }
    return 0;
}