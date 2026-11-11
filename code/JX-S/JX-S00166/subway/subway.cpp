#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod=998244353;
const int N=550020;
int c,n,m,d,q,k,cnt,ans;
int w[N],dis[N],vis[N];
map<int,int> ds[505];
vector<pair<int,int> >g[N];
vector<pair<int,int> >h[N];
struct node{
    int x,l;
    bool operator <(node w)const{
        return l>w.l;
    }
};
void solve(){
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        int x,t;
        for(int j=1;j<=k;j++){
            cin>>x>>t;
            h[x].push_back({i,t});
            g[x].push_back({m+i,t});
            g[m+i].push_back({x,t});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m+n;j++){
            dis[j]=1e18;
            vis[j]=0;
        }
        priority_queue<node>p;
        p.push((node){m+i,0});
        dis[m+i]=0;
        while(!p.empty()){
            node px=p.top();
            p.pop();
            if(vis[px.x])continue;
            vis[px.x]=1;
            for(auto v:g[px.x]){
                if(dis[px.x]+v.second<dis[v.first]){
                    dis[v.first]=dis[px.x]+v.second;
                    p.push((node){v.first,dis[v.first]});
                }
            }
        }
        for(int j=1;j<=m+n;j++){
            ds[i][j]=dis[j];
        }
    }
    int x,y;
    while(q--){
        cin>>x>>y;
        ans=1e18;
        for(auto v:h[x]){
            ans=min(ans,ds[v.first][y]+v.second);
        }
        for(auto v:h[y]){
            ans=min(ans,ds[v.first][x]+v.second);
        }
        cout<<ans+w[x]+w[y]<<endl;
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _=1;
    //cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
