#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using P=pair<ll,int>;
const int MAXM=2e4+5;
const int MAXN=505;
const ll INF=1e18;
int c,n,m,d,q;
int a[MAXN];
ll t[MAXN];
ll out[MAXN];
vector<pair<int,ll>>g[MAXM*MAXN];

int spec(int i,int k){
    return i+k*m;
}
ll dis[MAXM*MAXN];

void dj(int s){
    priority_queue<P,vector<P>,greater<P> >pq;
    pq.push({0,s});
    dis[s]=0;
    while(!pq.empty()){
        ll d=pq.top().first;
        int u=pq.top().second;
        pq.pop();
        if(d>dis[u]){
            continue;
        }
        for(auto e:g[u]){
            int v=e.first;
            ll w=e.second;
            if(dis[v]>=dis[u]+w){
                dis[v]=dis[u]+w;
                pq.push({dis[v],v});
            }
        }

    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>out[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[j]>>t[j];
            int idj=spec(a[j],i);
            g[idj].push_back({j,out[a[j]]});
            g[j].push_back({idj,out[a[j]]});
            if(j==1)continue;
            int idpre=spec(a[j-1],i);
            g[idj].push_back({idpre,0});
            g[idpre].push_back({idj,0});

    }
    }

    while(q--){
        int st,ed;
        cin>>st>>ed;
        for(int i=0;i<=m+n*m;i++){
            dis[i]=INF;
        }
       dj(st);
        cout<<dis[ed]<<endl;
    }
    return 0;
}
