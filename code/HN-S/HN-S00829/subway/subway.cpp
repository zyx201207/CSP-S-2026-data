#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const int M=5e5+5;
const int N=505;
ll c,n,m,d,q;
ll w[M],dis[M];
bool vis[M];
struct node{
    ll a,t;
};
struct NODE{
    ll to,dist;
};
vector<NODE> g[N];
namespace jyh{
    void A(){
        ll k;
        for(int i=1;i<=n;i++){
            vector<node> dt;
            cin>>k;
            ll a,t;
            for(int j=1;j<=k;j++){
                cin>>a>>t;
                dt.push_back({a,t});
            }
            for(int j=0;j<(int)dt.size();j++){
                for(int k=0;k<(int)dt.size();k++){
                    if(k==j)continue;
                    g[dt[j].a].push_back({dt[k].a,dt[j].t+dt[k].t});
                }
            }
        }
        deque<ll> dq;
        for(int i=1;i<=q;i++){
            while(!dq.empty())dq.pop_back();
            for(int j=0;j<=m;j++){
                dis[j]=0x3f3f3f3f;vis[j]=false;
            }
            ll st,en;
            cin>>st>>en;
            dis[st]=0;
            dq.push_back(st);
            while(!dq.empty()){
                ll u=dq.front();dq.pop_front();
                vis[u]=false;
                for(auto v:g[u]){
                    ll to=v.to,dist=v.dist+dis[u];
                    if(dis[to]>=dist){
                        dis[to]=dist;
                        if(!vis[to]){
                            vis[to]=true;
                            if(!dq.empty()&&dis[to]<=dis[dq.front()]){
                                dq.push_front(to);
                            }else{
                                dq.push_back(to);
                            }
                        }
                    }
                }
            }
            cout<<dis[en]+w[st]+w[en]<<'\n';
        }
    }
    void bl(){
        ll dist[505][505];
        for(int i=0;i<=m;i++){
            for(int j=0;j<=m;j++){
                dist[i][j]=0x3f3f3f3f;
            }
            dist[i][i]=0;
        }
        for(int i=1;i<=n;i++){
            vector<node> dt;
            ll kk,a,t;
            cin>>kk;
            for(int j=1;j<=kk;j++){
                cin>>a>>t;dt.push_back({a,t});
            }
            for(int j=0;j<(int)dt.size();j++){
                for(int k=0;k<(int)dt.size();k++){
                    if(j==k)continue;
                    dist[dt[j].a][dt[k].a]=min(dist[dt[j].a][dt[k].a],dt[j].t+dt[k].t);
                }
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                for(int k=1;k<=m;k++){
                    if(j==k)continue;
                    dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
                }
            }
        }
        for(int i=1;i<=q;i++){
            ll st,en;
            cin>>st>>en;
            cout<<dist[st][en]+w[en]+w[st]<<'\n';
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    if(m<=500){
        jyh::bl();
    }else{
        jyh::A();
    }
    return 0;
}

