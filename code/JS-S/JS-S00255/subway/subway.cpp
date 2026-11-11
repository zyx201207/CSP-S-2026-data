#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int INF=INT_MAX;
const int MAXN=505;
int w[MAXN];
int dis[MAXN];
int d[MAXN];
vector<int> a;
vector<pair<int,ll>> adj[500005];
int n,m,c,dc,q;
void dijstra(int s){
    for(int i=1;i<=m;i++){
        d[i]=INF;
    }
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
    d[s]=0;
    q.push({0,s});
    while(!q.empty()){
        ll di=q.top().first;
        int u=q.top().second;
        q.pop();
        if(di>d[u]){
            continue;
        }
        for(auto &edge:adj[u]){
            int v=edge.first;
            ll w=edge.second;
            if(d[u]+w<d[v]){
                d[v]=d[u]+w;
                q.push({d[v],v});
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c;
    cin>>n>>m>>dc>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        while(k--){
                int j;
            cin>>j;
            a.push_back(j);
            cin>>dis[j];
        }
        for(int i=0;i<a.size();i++){
            for(int j=0;j<a.size();j++){
                if(i!=j){
                    adj[i].push_back({j,dis[i]+dis[j]});
                }
            }
        }
    }
    for(int i=1;i<=q;i++){
            int s;int e;
        cin>>s>>e;
        dijstra(s);
        cout<<d[e]+w[s]+w[e]<<(i==q?"":"\n");
    }
    return 0;
}
