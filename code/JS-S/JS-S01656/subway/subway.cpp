#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll inf=1e18;

struct info{
    int y,v;
    info(int _y,int _v){y=_y,v=_v;};
};

const int N=5e5+500+1;

int c,n,m,D,tc;
ll dist[N],d[501][501];
set<pair<ll,int>> q;
vector<info> g[N];

inline void dij(int s){
    q.clear();
    for(int i=1;i<=m+n;i++) dist[i]=inf;
    dist[s]=0;
    for(int i=1;i<=m+n;i++) q.insert({dist[i],i});
    while(q.size()){
        int x=q.begin()->second;q.erase(q.begin());
        if(dist[x]==inf) break;
        for(auto i:g[x])
            if(dist[x]+i.v<dist[i.y])
                q.erase({dist[i.y],i.y}),
                dist[i.y]=dist[x]+i.v,
                q.insert({dist[i.y],i.y});
    }
    for(int i=m+1;i<=m+n;i++) d[s-m][i-m]=dist[i];
}

inline void bfs(int s){
    queue<int> que;que.push(s);
    for(int i=1;i<=n+m;i++) dist[i]=-1;
    dist[s]=0;
    while(que.size()){
        int x=que.front();que.pop();
        for(auto i:g[x]) if(dist[i.y]==-1)
            dist[i.y]=dist[x]+1,que.push(i.y);
    }
    for(int i=m+1;i<=m+n;i++) d[s-m][i-m]=dist[i];
}

void solve(){
    cin>>c>>n>>m>>D>>tc;
    vector<int> w(m+1);
    for(int i=1;i<=m;i++) cin>>w[i];
    int cnt=m;
    ll T=-1;
    for(int i=1;i<=n;i++){
        cnt++;int k;cin>>k;
        for(int j=1;j<=k;j++){
            int f,v;cin>>f>>v;
            T=v;
            g[f].push_back(info(cnt,v)),
            g[cnt].push_back(info(f,v));
        }
    }
    if(12<=c&&c<=19){
        for(int i=m+1;i<=m+n;i++) bfs(i);
        while(tc--){
            int x,y;cin>>x>>y;
            ll ans=LLONG_MAX;
            for(auto i:g[x]) for(auto j:g[y])
                ans=min(ans,i.v+j.v+d[i.y-m][j.y-m]*T);
            ans+=w[x]+w[y];
            cout<<ans<<"\n";
        }
        return;
    }
    for(int i=m+1;i<=m+n;i++) dij(i);
    while(tc--){
        int x,y;cin>>x>>y;
        ll ans=LLONG_MAX;
        for(auto i:g[x]) for(auto j:g[y])
            ans=min(ans,i.v+j.v+d[i.y-m][j.y-m]);
        ans+=w[x]+w[y];
        cout<<ans<<"\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    solve();
    return 0;
}
