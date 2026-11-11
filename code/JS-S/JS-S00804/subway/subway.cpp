#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int,int>
const int N=5e5+10;
int n,m,c,d,q,s,e;
ll dis[2*N+1000];
bool vis[2*N+1000];
struct node{
    int to,w;
};
vector<node> G[2*N+1000];
void dijkstra(){
    priority_queue<PII,vector<PII>,greater<PII> > q;
    q.push({0,s});
    while(!q.empty()){
        auto tp=q.top();
        q.pop();
        if(vis[tp.second])continue;
        vis[tp.second]=1;
        for(auto v:G[tp.second]){
            if(dis[v.to]>dis[tp.second]+v.w){
                dis[v.to]=dis[tp.second]+v.w;
                q.push({dis[v.to],v.to});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        int x;
        cin>>x;
        G[i].push_back({i+m,x});
        G[i+m].push_back({i,x});
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            G[a+m].push_back({2*m+i,t});
            G[2*m+i].push_back({a+m,t});
        }
    }
//    for(int i=1;i<=2*m+n;i++){
//        for(auto v:G[i]){
//            cout<<v.to<<" "<<v.w<<endl;
//        }
//        cout<<endl;
//    }
    for(int i=1;i<=q;i++){
        memset(vis,0,sizeof(vis));
        memset(dis,0x3f,sizeof(dis));
        cin>>s>>e;
        dis[s]=0;
        dijkstra();
        cout<<dis[e]<<endl;
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
