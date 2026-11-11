#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=600;
const int MAXM=600005;
#define inf 1000000000000000000
int n,m,q;
int w[MAXM];
vector<pair<int,int>> a[MAXM];

/*int n,m;*/
vector<pair<int,int>> e[MAXN];
int d[MAXN];
bool vis[MAXN];
int dij(int c,int o){
    for(int i=1;i<=n;i++) d[i]=inf,vis[i]=0;
    d[c]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
    pq.push({0,c});
    while(!pq.empty()){
        auto x=pq.top();
        pq.pop();
        #define u x.second
        #define v i.first
        #define w i.second
        //cout<<u<<endl;
        if(u==o) break;
        //cout<<u<<endl;
        if(vis[u]) continue;
        vis[u]=1;
        //cout<<u<<endl;
        for(auto i:e[u]){
                //cout<<u<<v<<w<<endl;
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
        //<<u<<v<<w<<endl;
                if(!vis[v])pq.push({d[v],v});
            }
        }
        #undef u
        #undef v
        #undef w
    }
    return d[o];
}


signed main(){
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,d;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int s,t;
            cin>>s>>t;
            a[s].push_back({i,t});
        }
    }
   // cout<<"fsda"<<endl;
    for(int i=1;i<=m;i++){
        for(auto j:a[i]){
            for(auto  k:a[i]){
                if(j.first==k.first)continue;
                e[j.first].push_back({k.first,j.second+k.second});
                //cout<<j.first<<' '<<k.first<<' '<<j.second+k.second<<endl;
            }
        }
    }
   //cout<<"fdsa"<<endl;
    while(q--){
        int x,y;
        cin>>x>>y;
        int ans=inf;
        for(auto i:a[x]){
            for(auto j:a[y]){
             //cout<<i.first<<' '<<j.first<<endl;
                 int sm=dij(i.first,j.first)+i.second+j.second;
                 ans=min(ans,sm);
            }
        }
        cout<<ans+w[x]+w[y]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
