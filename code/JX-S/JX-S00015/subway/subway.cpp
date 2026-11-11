#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=510,M=2e4+10;

struct Node{
    ll x,y;
}r[N];
ll c,n,m,d,p,w[N],t[N][M],a[N][M];
ll vis[N],dis[N],k[N],x[N][M],s,z[N],l[N],cnt1=0,cnt2=0;

vector<pair<ll,ll>>g[M];
void f(){
    memset(dis,127,sizeof(dis));
    memset(vis,0,sizeof(vis));
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> q;
    q.push({0,s});
    while(!q.empty()){
        pair<ll,ll>tp=q.top();
        ll u=tp.second;
        q.pop();
        for(auto [v,w]:g[u]){
            if(dis[u]+w>dis[v]){
                dis[v]=dis[u]+w;
                q.push({dis[v],v});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }

    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>x[i][j]>>c;
            a[i][x[i][j]]++;
            t[i][x[i][j]]=c+w[x[i][j]];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            ll mina=INT_MAX,minb;
            for(int l=1;j<=k[i];l++){
                if(a[j][x[j][l]]){
                    mina=min(mina,t[j][x[j][l]]);
                    minb=min(minb,t[i][x[i][l]]);
                }
            }
            g[i].push_back({j,mina});
            g[j].push_back({i,minb});
        }
    }
    for(int i=1;i<=p;i++){
        cin>>r[i].x>>r[i].y;
        for(int j=1;j<=n;j++){
            if(a[i][r[i].x]){
                z[++cnt1]=i;
            }
            if(a[i][r[i].y]){
                l[++cnt2]=i;
            }
        }
        ll minn=INT_MAX;
        for(int j=1;j<=cnt1;j++){
            for(int q=1;q<=cnt2;q++){
                s=z[j];
                f();
                minn=min(minn,dis[l[q]]);
            }
        }
        cout<<minn<<"\n";
    }
    return 0;
}
