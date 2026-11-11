#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

const int MAXN=30,INF=1e9+7;
vector<int> g[MAXN];
int c,t,n,k;

int fa[MAXN];
int find(int x){
    if(fa[x]!=x) fa[x]=find(fa[x]);
    return fa[x];
}

int dis[MAXN],st[MAXN];
void dij(int s){
    memset(dis,0x3f,sizeof dis);
    memset(st,0,sizeof st);
    priority_queue<pii,vector<pii>,greater<pii> >pq;

    dis[s]=0;
    pq.push({0,s});
    while(!pq.empty()){
        int u=pq.top().second; pq.pop();
        if(st[u]) continue;
        st[u]=1;
        for(int v:g[u]){
            if(dis[u]+1<dis[v]){
                dis[v]=dis[u]+1;
                pq.push({dis[v],v});
            }
        }
    }
}

int S[MAXN];
vector<int> cand;
void solve1(){
    for(int i=1;i<=n;i++) S[i]=i;
    int ans=INF;
    do{
        for(int mask=0;mask<(1<<n);mask++){
            cand.clear();
            for(int i=0;i<n;i++){
                if((mask>>i)&1){
                    cand.push_back(S[i+1]);
                }
            }
            if(cand.size()!=k) continue;
            set<int> ssy;
            for(int x:cand) ssy.insert(find(x));
            if(ssy.size()>2) continue;

            int d=0;
            for(int i=1;i<=n;i++){
                dij(i);
                int mn=INF;
                for(int j:cand) mn=min(mn,dis[j]);
                d=max(d,mn);
            }
            ans=min(ans,d);
        }
    }while(next_permutation(S+1,S+n+1));
    cout<<ans<<"\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    cin>>c>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++) fa[i]=i;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
            u=find(u),v=find(v);
            if(u!=v) fa[u]=v;
        }
        solve1();
    }


    return 0;
}
