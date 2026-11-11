

#include<bits/stdc++.h>
using namespace std;
const long long inf=1e18;
long long c,T,n,d,x[5010],ans=0;
queue<int>q;
bool vis[5010];
int dis[5010],num[5010];
void bfs(int s){
    while(q.size()) q.pop();
    for(int i=s+1;i<=n;++i){
        vis[i]=false;
    }
    for(int i=s+1;i<=n;++i){
        dis[i]=inf;
    }
    for(int i=s+1;i<=n;++i){
        num[i]=0;
    }
    q.push(s);
    vis[s]=true;
    dis[s]=0;
    num[s]=1;
    int u;
    while(q.size()){
        u=q.front();
        q.pop();
        for(int i=u+1;x[i]-x[u]<=d && i<=n;++i){
            if(vis[i]){
                if(dis[i]==dis[u]+1){
                    num[i]+=num[u];
                }
                continue;
            }
            dis[i]=dis[u]+1;
            num[i]=num[u];
            vis[i]=true;
            q.push(i);
        }
    }
    for(int i=s+1;i<=n;++i){
        if(num[i]==2){
            ++ans;
        }
    }
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&T);
    while(T--){
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;++i){
            scanf("%lld",&x[i]);
        }
        ans=0;
        for(int i=1;i<=n;++i){
            bfs(i);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

