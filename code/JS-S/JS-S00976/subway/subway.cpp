#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,n,m,d,q,xx,x,y,u,g,wher,vvv;
ll zz,now,qqq;
ll w[500010];
vector<pair<int,ll>> v[510];
vector<pair<int,ll> > e[500010]; // lu      fei
ll ans;
priority_queue<pair<ll,pair<int,int> > > pq;   //zhi     dian   lu
pair<ll,pair<int,int> > wasd;
ll dist[100001];
void solve(){
    cin>>x>>y;
    ans=0;
    ans+=w[x];ans+=w[y];
    for(int i=1;i<=m;i++){
        dist[i]=1e18;
    }
    dist[x]=0;
    wasd.first=0;
    wasd.second.first=x;
    wasd.second.second=0;
    pq.push(wasd);
    while(!pq.empty()){
        u=pq.top().second.first;
        g=pq.top().second.second;
        pq.pop();//cout<<u<<" "<<g<<endl;
        qqq=0;
        for(int i=0;i<e[u].size();i++){
            if(e[u][i].first==g){
                qqq=e[u][i].second;
            }
        }
        for(int i=0;i<e[u].size();i++){
            if(e[u][i].first==g){
                continue;
            }
            vvv=e[u][i].first;
            for(int j=1;j<=v[vvv][0].first;j++){
                if(v[vvv][j].first==u){
                    wher=j;break;
                }
            }
            now=wher+1;//cout<<vvv<<" "<<wher<<" "<<v[vvv][wher].first<<endl;
            while(now<=v[vvv][0].first){
                    if(dist[v[vvv][now].first]>(dist[u]+e[u][i].second+v[vvv][now].second)){
                        dist[v[vvv][now].first]=(dist[u]+e[u][i].second+v[vvv][now].second);
                        wasd.first=-dist[v[vvv][now].first];
                        wasd.second.first=v[vvv][now].first;
                        wasd.second.second=vvv;
                        pq.push(wasd);
                    }
                    now++;

            }
            now=wher-1;//cout<<vvv<<" "<<wher<<" "<<v[vvv][wher].first<<endl;
            while(now>0){
                    if(dist[v[vvv][now].first]>(dist[u]+e[u][i].second+v[vvv][now].second)){
                        dist[v[vvv][now].first]=(dist[u]+e[u][i].second+v[vvv][now].second);
                        wasd.first=-dist[v[vvv][now].first];
                        wasd.second.first=v[vvv][now].first;
                        wasd.second.second=vvv;
                        pq.push(wasd);
                    }
                    now--;

            }
        }
    }
    cout<<(dist[y]+ans)<<endl;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>xx;
        v[i].push_back({xx,0});
        for(int j=1;j<=v[i][0].first;j++){
            cin>>xx>>zz;
            v[i].push_back({xx,zz});
            e[xx].push_back({i,zz});
        }
    }
    while(q--){
        solve();
    }
    return 0;
}
