#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int N = 5e5+505;
int n,m,c,d1,q,ans;
int w[N];
long long d[N];
vector<pair<int,int>>e[N];
void dij(int r,int s){
    memset(d,0x3f,sizeof(d));
    priority_queue<pair<ll,int>>q;
    d[r]=0;
    q.push({d[r],r});
    while(!q.empty()){
        auto [t,u]=q.top();q.pop();
        if(t!=d[u])continue;
        if(u==s)return ;
        for(auto &[v,w]:e[u]){
            if(d[u]+w<d[v]){
                d[v]=d[u]+w;
                q.push({d[v],v});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d1>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int u=i+m,k;cin>>k;
        for(int j=1;j<=k;j++){
            int v,t;
            cin>>v>>t;
            e[v].push_back({u,t});
            e[u].push_back({v,t});
        }
    }
    while(q--){
        int r,s;
        cin>>r>>s;
        dij(r,s);
        //for(int i=1;i<=m+n;i++)cout<<d[i]<<" ";
        cout<<d[s]+w[r]+w[s]<<'\n';
    }
    return 0;
}
