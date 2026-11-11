#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+7,M=5007,INF=2e9;
int dis[M][M],vis[M][M],cnt[M][M];
int c,t,n;
ll a[N];
ll m,ans;
vector<int>G[N];
queue<int>q;
void Init(){
    ans=0ll;
    for(int i=1;i<=n;i++) G[i].clear();
}
void bfs(int s){
    while(q.size()) q.pop();
    q.push(s);
    for(int i=1;i<=n;i++) if(i!=s){
        dis[s][i]=INF;
        vis[s][i]=cnt[s][i]=0;
    }
    vis[s][s]=0;
    cnt[s][s]=1;
    while(q.size()){
        int u=q.front();
        q.pop();
        if(vis[s][u]) continue;
        vis[s][u]=1;
        for(int v: G[u]){
            if(dis[s][v]>dis[s][u]+1){
                dis[s][v]=dis[s][u]+1;
                cnt[s][v]=cnt[s][u];
            }
            else if(dis[s][v]==dis[s][u]+1){
                if(cnt[s][v]==INF) cnt[s][u]=INF;
                else cnt[s][v]+=cnt[s][u];
            }
            if(cnt[s][v]>2) cnt[s][v]=INF;
            q.push(v);
        }
    }
}
void solve(){
    scanf("%d%lld",&n,&m);
    Init();
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    if(c==11||c==12){
        ll len=a[2]-a[1],num=m/len;
        for(int i=1;i<=n;i++){
            if(i+num>=n) break;
            ans+=1ll*min(1ll*n,1ll*i+(num<<1)-1)-1ll*(1ll*i+num)+1ll;
        }
        printf("%lld\n",ans);
        return;
    }
    //if(c<=10){
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j&&abs(a[i]-a[j])<=m) G[i].push_back(j);
        for(int i=1;i<=n;i++){
            bfs(i);
            for(int j=i+1;j<=n;j++) if(cnt[i][j]==2) ans+=1ll;
        }
        printf("%lld\n",ans);
        return;
    //}
}
void Files(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
}
int main(){
    Files();
    scanf("%d%d",&c,&t);
    while(t--) solve();
    return 0;
}
