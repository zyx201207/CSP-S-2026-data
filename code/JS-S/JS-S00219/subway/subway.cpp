#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
#define endl '\n'
const int maxn=5e5+10,maxm=5e2+10;
int w[maxn],a[maxn][maxm];
struct node{
    int v,w;
};
vector<node>g[maxm];
vector<int>bl[maxn];
set<int>ji;
int dis[maxn];
struct cmp{
    bool operator () (node x,node y){
        return x.w>y.w;
    }
};
int dij(int s,int t){
    memset(dis,0x3f,sizeof(dis));
    priority_queue<node,vector<node>,cmp>q;
    dis[s]=0;q.push((node){s,0});
    while(q.size()){
        int u=q.top().v,w=q.top().w;q.pop();
        if(w!=dis[u])continue;
        for(auto v:g[u]){
            if(dis[v.v]>dis[u]+v.w){
                dis[v.v]=dis[u]+v.w;
                q.push((node){v.v,dis[v.v]});
            }
        }
    }
    return dis[t];
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x;
            cin>>x;
            bl[x].push_back(i);
            if(bl[x].size()>1)ji.insert(x);
            cin>>a[x][i];
        }

    }
    for(auto i:ji){
        for(int j=0;j<bl[i].size();j++){
            for(int k=j+1;k<bl[i].size();k++){
                g[bl[i][j]].push_back((node){bl[i][k],a[i][bl[i][j]]+a[i][bl[i][k]]});
                g[bl[i][k]].push_back((node){bl[i][j],a[i][bl[i][j]]+a[i][bl[i][k]]});
            }
        }
    }
    for(int i=1;i<=q;i++){
        int s,t;
        cin>>s>>t;
        int mn=INT_MAX;
        for(int j=0;j<bl[s].size();j++){
            for(int k=0;k<bl[t].size();k++){
                mn=min(mn,dij(bl[s][j],bl[t][k])+w[s]+w[t]+a[s][bl[s][j]]+a[t][bl[t][k]]);
            }
        }
        cout<<mn<<endl;
    }
    return 0;
}
