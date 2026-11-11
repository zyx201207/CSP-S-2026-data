#include<bits/stdc++.h>
using namespace std;
const long long M=6e5+10;
long long c,n,m,d,Q,tw[M],s,t,dis[M];
bool sure[M];
vector<pair<long,long> > e[M];
priority_queue<pair<long,long>,vector<pair<long,long> >,greater<pair<long,long> > > q;
void dij(){
    memset(sure,0,sizeof(sure));
    memset(dis,0x7f,sizeof(dis));
    q.push({0,s});
    dis[s]=0;
    while(!q.empty()){
        long long p=q.top().second;
        q.pop();
        if(sure[p]) continue;
        else sure[p]=true;
        //cout<<p<<" "<<dis[p]<<" "<<dis[6]<<"\n";
        if(p==t) break;
        for(pair<long,long> i:e[p]){
            long long v=i.first,w=i.second;
            if(dis[v]>dis[p]+w){
                dis[v]=dis[p]+w;
                q.push({dis[v],v});
            }
        }
    }
    while(!q.empty()) q.pop();
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>c>>n>>m>>d>>Q;
    for(long long i=1;i<=m;i++) cin>>tw[i];
    for(long long i=1;i<=n;i++){
        long long k;
        cin>>k;
        for(long long j=1;j<=k;j++){
            long long u,w,v=i+m;
            cin>>u>>w;
            e[u].push_back({v,w});
            e[v].push_back({u,w});
        }
    }
    for(long long i=1;i<=Q;i++){
        cin>>s>>t;
        dij();
        cout<<dis[t]+tw[s]+tw[t]<<"\n";
    }

    return 0;
}
