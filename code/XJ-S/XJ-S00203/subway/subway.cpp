#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5.5e5;
struct node{
    int to,val;
};
struct edge{
    int idx,val;
    friend bool operator<(const edge v,const edge u){
        return v.val>u.val;
    }
};
int c,n,m,d,Q;
int w[N],dis[N];
vector<node> e[N];
priority_queue<edge> q;
int dij(int s,int t){
    memset(dis,0x3f,sizeof dis);
    dis[s]=0;
    q.push({s,0});
    while(!q.empty()){
        edge tmp=q.top();
        q.pop();
        for(auto v:e[tmp.idx]){
            if(dis[tmp.idx]+v.val<dis[v.to]){
                dis[v.to]=dis[tmp.idx]+v.val;
                q.push({v.to,dis[tmp.idx]+v.val});
            }
        }
    }
    return dis[t];
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>Q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1,k;i<=n;i++){
        cin>>k;
        for(int j=1,a,t;j<=k;j++){
            cin>>a>>t;
            e[i+m].push_back({a,t});
            e[a].push_back({i+m,t});
        }
    }
    while(Q--){
        int s,t;
        cin>>s>>t;
        cout<<dij(s,t)+w[s]+w[t]<<"\n";
    }
    return 0;
}