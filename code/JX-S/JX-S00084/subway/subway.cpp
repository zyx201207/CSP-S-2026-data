#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int c,n,m,d,q,k;
const int N = 5e5+5;
const int INF = 0x3f3f3f3f;
int w[N];
int a[N];
int t[N];
int kou[N];
int zan[N];
int l[N];
int tai[N];
vector<pair<int,int> >adj[N];
vector<int>dijkstra(int s){
    vector<int>dist(m+1,INF);
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
    q.push({0,s});
    dist[s]=0;
    while(!q.empty()){
        auto p=q.top();
        q.pop();
        if(dist[p.second]!=p.first){
            continue;
        }
        for(auto[v,w]:adj[p.second]){
            if(dist[v]>dist[p.second]+w){
                dist[v]=min(dist[p.second]+w,dist[v]);
                q.push({dist[v],v});
            }
        }
    }
    return dist;
}
signed main(){
    //freopen("subway.in","r",stdin);
    //freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++){
        kou[i]=i;
        zan[i]=i+n;
        l[i]=i+3*n;
        tai[i]=i+2*n;
    }
    for(int i=1;i<=m;i++){
        cin>>w[i];
        adj[kou[i]].push_back({tai[i],w[i]});
        adj[tai[i]].push_back({kou[i],w[i]});
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[j]>>t[j];
            adj[l[i]].push_back({tai[j],t[j]});
            adj[tai[j]].push_back({l[i],t[j]});
            adj[l[i]].push_back({a[j],0});
            adj[a[j]].push_back({l[i],0});
        }
    }

    while(q--){
        int s,e;
        cin>>s>>e;
        vector<int>dist1=dijkstra(s);
        cout<<dist1[e]<<endl;
    }
    return 0;
}
