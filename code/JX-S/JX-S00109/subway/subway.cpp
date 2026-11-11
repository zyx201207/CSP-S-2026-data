#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,q;
ll w[500005];
bool vis[500505];
map<int,ll> ee[505];
ll D[505];
map<int,ll> zhan[500505];
priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> Q;
ll bfs(int s,int t){
    while(!Q.empty())Q.pop();
    memset(vis,0,sizeof(vis));
    memset(D,0x3f,sizeof(D));
    for (auto[x,l]:zhan[s]){
        Q.push({l,x});
        D[x]=l;
    }
    while(!Q.empty()){
        auto[dd,u]=Q.top();
        Q.pop();
        if (vis[u])continue;
        vis[u]=1;
        for (auto[x,l]:ee[u]){
            if (l+dd<D[x]){
                D[x]=dd+l;
                Q.push({D[x],x});
            }
        }
    }
    ll anss=0x3f3f3f3f3f3f3f3f;
    int sss=0;
    for (auto[x,l]:zhan[t]){
        if (anss>D[x]+l){
            sss=x;
            anss=D[x]+l;
        }
    }
    anss+=w[s-n];
    anss+=w[t-n];
    return anss;
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++)cin>>w[i];
    for (int i=1;i<=n;i++){
        int k;
        cin>>k;
        for (int j=1;j<=k;j++){
            int a;ll t;
            cin>>a>>t;
            for (auto[x,l]:zhan[a+n]){
                if (ee[i][x]==0){
                    ee[i][x]=l+t;
                    ee[x][i]=l+t;
                }
                else{
                    ee[i][x]=min(ee[i][x],l+t);
                    ee[x][i]=ee[i][x];
                }
            }
            zhan[a+n][i]=t;
        }
    }
    for (int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        x+=n;
        y+=n;
        ll ans=bfs(x,y);
        cout<<ans<<"\n";

    }


}
