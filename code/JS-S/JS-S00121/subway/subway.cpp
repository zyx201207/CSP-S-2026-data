#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=5e5+10;
struct nod{
    int id,u;
};
struct str{
    int k,id,l;
    bool operator>(const str& xxx)const{
        return l<xxx.l;
    }
    bool operator<(const str& xxx)const{
        return l>xxx.l;
    }
};
int c,n,m,d,q;
vector<nod>g[N];
map<pair<int,int>,int>vh;
int w[N];
bool vis[5010];
int wis[5010][5010];
void Dij(int st){
    memset(vis,0,sizeof(vis));
    priority_queue<str>q;
    wis[st][st]=0;
    q.push({st,0,0});
    while(!q.empty()){
        int s=q.top().l,k=q.top().k,id=q.top().id;
        q.pop();
        if(vis[k]){
            continue;
        }
        vis[k]=1;
        for(auto i:g[k]){
            int u=i.u;
            if(i.id==id&&wis[st][u]>s){
                q.push({i.u,id,s});
                wis[st][u]=s;
            }else if(wis[st][u]>s+vh[{k,i.id}]+vh[{u,i.id}]){
                q.push({u,i.id,s+vh[{k,i.id}]+vh[{u,i.id}]});
                wis[st][u]=s+vh[{k,i.id}]+vh[{u,i.id}];
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(wis,16,sizeof(wis));
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i){
        cin>>w[i];
        vh[{i,0}]=w[i];
    }
    for(int i=1;i<=n;++i){
        int k,p,t;
        cin>>k>>p>>t;
        vh[{p,i}]=t;
        for(int j=2;j<=k;++j){
            int p2,t2;
            cin>>p2>>t2;
            vh[{p2,i}]=t2;
            g[p].push_back({i,p2});
            p=p2;
            t=t2;
        }
    }
    for(int i=1;i<=m;++i){
        Dij(i);
    }
    while(q--){
        int u,v;
        cin>>u>>v;
        cout<<wis[u][v]+w[u]+w[v]<<endl;
    }
    return 0;
}