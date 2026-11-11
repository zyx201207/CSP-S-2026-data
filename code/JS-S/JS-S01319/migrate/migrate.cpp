#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+2;
int n;
ll d;
ll x[N],cnt[N],dis[N];
bool vis[N];
inline void Dijkstra(int st) {
    priority_queue <pair <ll,int>> q;
    q.push({0,st});
    cnt[st]=1;
    while(!q.empty()) {
        int u=q.top().second;
        q.pop();
        if(vis[u])  continue;
        vis[u]=1;
        for(int l=u-1;l>=1;l--) {
            if(abs(x[l]-x[u])>d)    break;
            if(dis[u]+1<dis[l]) {
                dis[l]=dis[u]+1;
                cnt[l]=cnt[u];
                q.push({-dis[l],l});
            } else if(dis[u]+1==dis[l]) cnt[l]+=cnt[u];
        }
        for(int l=u+1;l<=n;l++) {
            if(abs(x[l]-x[u])>d)    break;
            if(dis[u]+1<dis[l]) {
                dis[l]=dis[u]+1;
                cnt[l]=cnt[u];
                q.push({-dis[l],l});
            } else if(dis[u]+1==dis[l]) cnt[l]+=cnt[u];
        }
    }
}
inline void Solve() {
    cin>>n>>d;
    ll res=0;
    for(int i=1;i<=n;i++)   cin>>x[i];
    for(int j=1;j<=n;j++)   dis[j]=1e18,cnt[j]=0,vis[j]=0;
    for(int i=1;i<=n;i++) {
        dis[i]=0;
        Dijkstra(i);
        for(int j=1;j<=n;j++) {
            if(cnt[j]==2)   ++res;
            dis[j]=1e18,cnt[j]=0,vis[j]=0;
        }
    }
    cout<<res/2<<"\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--)  Solve();
    return 0;
}