#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+10;
struct node{
    ll to,val;
};
ll c,n,m,d,q;
ll w[N];
bool vis[501];
ll dis[501][501];
vector<node> firG[N];
vector<node> G[501];
priority_queue<pair<ll,ll> > Q;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(ll i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }
    ll k,a,t;
    for(ll i=1;i<=n;i++){
        scanf("%lld",&k);
        while(k--){
            scanf("%lld%lld",&a,&t);
            node e;
            e.to=a;e.val=t;
            firG[i+m].push_back(e);
            e.to=i+m;
            firG[a].push_back(e);
        }
    }
    for(ll i=1;i<=m;i++){
        for(ll j=0;j<firG[i].size()-1;j++){
            for(ll k=j+1;k<firG[i].size();k++){
                node e;
                e.to=firG[i][k].to-m;
                e.val=firG[i][j].val+firG[i][k].val;
                G[firG[i][j].to-m].push_back(e);
                e.to=firG[i][j].to-m;
                G[firG[i][k].to-m].push_back(e);
            }
        }
    }
//=================================
    ll u,v,sum,ww;
    for(ll s=1;s<=n;s++){
        for(ll i=1;i<=n;i++){
            vis[i]=0;
            dis[s][i]=1e12;
        }

        dis[s][s]=0;
        Q.push(make_pair(0,s));

        while(!Q.empty()){
            u=Q.top().second;
            sum=-Q.top().first;
            Q.pop();
            if(vis[u]){
                continue;
            }
            vis[u]=1;
            for(ll i=0;i<G[u].size();i++){
                v=G[u][i].to;
                ww=G[u][i].val;
                if(sum+ww<dis[s][v]){
                    dis[s][v]=sum+ww;
                    Q.push(make_pair(-dis[s][v],v));
                }
            }
        }
    }
//===============================
    ll x,y,ans;
    while(q--){
        ans=1e12;
        scanf("%lld%lld",&x,&y);
        for(ll i=0;i<firG[x].size();i++){
            for(ll j=0;j<firG[y].size();j++){
                ans=min(ans,firG[x][i].val+firG[y][j].val+dis[firG[x][i].to-m][firG[y][j].to-m]);
            }
        }
        printf("%lld\n",ans+w[x]+w[y]);
    }
    return 0;
}
//zczxnbnbnb
