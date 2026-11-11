#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=505,M=5e5+5;
struct Node{
    vector<ll> edge;
    vector<ll> nul;
};
Node node[M];
ll a[N][N];
ll ddis[N][N];
ll gzh[M];
struct AAA{
    ll u,step;
    bool operator<(const AAA other)const{
        return step<other.step;
    }
};
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ll c,n,m,d,q;scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    memset(a,0x3f,sizeof(a));
    memset(ddis,0x3f,sizeof(ddis));
    for(ll i=1;i<=m;i++)scanf("%lld",&gzh[i]);
    for(ll i=1;i<=n;i++){
        a[i][i]=0;
        ll x;scanf("%lld",&x);
        for(ll j=1;j<=x;j++){
            ll v,nul;scanf("%lld%lld",&v,&nul);
            node[v].edge.push_back(i);
            node[v].nul.push_back(nul);
        }
    }
    for(ll i=1;i<=m;i++){
        ll s=node[i].edge.size();
        for(ll j=0;j<s;j++){
            for(ll k=0;k<j;k++){
                ll u=node[i].edge[j];
                ll v=node[i].edge[k];
                ll tmp=node[i].nul[j]+node[i].nul[k];
                a[u][v]=min(a[u][v],tmp);
                a[v][u]=min(a[v][u],tmp);
            }
        }
    }
    for(ll i=1;i<=n;i++){
        priority_queue<AAA> ss;
        ss.push({i,0});
        ddis[i][i]=0;
        while(!ss.empty()){
            ll u=ss.top().u,step=ss.top().step;
            ss.pop();
            for(ll j=0;j<=n;j++){
                if(step+a[u][j]<ddis[i][j]){
                    ddis[i][j]=step+a[u][j];
                    ss.push({j,ddis[i][j]});
                }
            }
        }
    }
    while(q--){
        ll x,y;scanf("%lld%lld",&x,&y);
        ll ans=gzh[x]+gzh[y];
        ll tmp=0x3f3f3f3f3f3f3f3f;
        ll sx=node[x].edge.size(),sy=node[y].edge.size();
        for(ll i=0;i<sx;i++){
            for(ll j=0;j<sy;j++){
                    //cout<<x<<" "<<y<<" "<<node[x].nul[i]<<" "<<node[y].nul[j]<<" "<<ddis[node[x].edge[i]][node[y].edge[j]]<<" "<<node[x].edge[i]<<" "<<node[y].edge[j]<<endl;
                tmp=min(tmp,node[x].nul[i]+node[y].nul[j]+ddis[node[x].edge[i]][node[y].edge[j]]);
            }
        }
        printf("%lld\n",ans+tmp);
    }
    return 0;
}
