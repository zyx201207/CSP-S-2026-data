#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,Q;
long long w[500005];
vector<pair<long long,long long> >g[600005];
long long dis[600005];
bool vis[600005];
long long ans=0;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>Q;
    for(long long i=1;i<=m;++i){
        cin>>w[i];
    }
    long long x,v,wi;
    for(long long i=1,u=m+1;i<=n;++i,++u){
        cin>>x;
        while(x--){
            cin>>v>>wi;
            g[u].push_back({wi,v});
            g[v].push_back({wi,u});
        }
    }
    long long s,t;
    while(Q--){
        cin>>s>>t;
        ans+=w[s];
        ans+=w[t];
        for(long long i=1;i<=n+m;++i){
            dis[i]=0x3f3f3f3f3f3f3f3f;
            vis[i]=false;
        }
        dis[s]=0;
        priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > >q;
        q.push({0,s});
        while(!q.empty()){
            long long tmp=q.top().second;
            q.pop();
            if(vis[tmp])continue;
            vis[tmp]=true;
            for(long long i=0;i<g[tmp].size();++i){
                long long t1=g[tmp][i].second;
                long long t2=g[tmp][i].first;
                if(dis[t1]>dis[tmp]+t2){
                    dis[t1]=dis[tmp]+t2;
                    q.push({dis[t1],t1});
                }
            }
        }
        ans+=dis[t];
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}
