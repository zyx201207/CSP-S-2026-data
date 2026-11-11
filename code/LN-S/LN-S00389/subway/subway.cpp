#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,k) for(ll i=j;i<=k;i++)
struct code{
    ll to,w,op;
    friend bool operator < (code a,code b){
        return a.w<b.w;
    }
};
vector<code> v[500005],y[505];
ll n,m,c,T,k;
ll h[500005];
priority_queue<code> q;
ll dis[500005],vis[505];
ll bfs(ll fg){
    dis[fg]=0;
    q.push({0,fg,0});
    while(!q.empty()){

        ll x=q.top().w;
        ll u=q.top().to;
        ll bb=q.top().op;
        q.pop();
    //cout<<x<<u<<bb<<" ";
        if(bb==0){
        if(dis[x]<u&&dis[x]>0) continue;
        for(auto i:v[x]){
            if(vis[i.to]==-1||vis[i.to]>i.w+u){
                vis[i.to]=i.w+u;
                q.push({i.w+u,i.to,1});
            }
        }
        }
        else{
        if(vis[x]<u&&vis[x]>0) continue;

        for(auto i:y[x]){
            if(dis[i.to]==-1||dis[i.to]>i.w+u){
                dis[i.to]=i.w+u;
                q.push({i.w+u,i.to,0});
            }
        }
        }
    }
    return 0;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>k>>T;
    f(i,1,m) cin>>h[i];
    f(i,1,n){
        ll k;
        cin>>k;
        f(j,1,k){
            ll aa,tt;
            cin>>aa>>tt;
            v[aa].push_back({i,tt,1});
            y[i].push_back({aa,tt,0});
        }
    }
    while(T--){
        memset(dis,-1,sizeof(dis));
        memset(vis,-1,sizeof(vis));
        ll x,y;
        cin>>x>>y;
        bfs(x);
        //f(i,1,m) cout<<dis[i]<<" ";
        cout<<dis[y]+h[x]+h[y]<<endl;
    }
}/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
