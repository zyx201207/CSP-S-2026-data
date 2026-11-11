#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10,M=6e5+505;
int n,m,c,dd,qq,p[M*2],cnt,w[N];
struct Edge{
    int v,w,nxt;
}e[M*2];
void init(int u,int v,int w){
    e[++cnt].v=v;
    e[cnt].w=w;
    e[cnt].nxt=p[u];
    p[u]=cnt;
    return;
}
int idsub(int x){
return x;
}
int idting(int x){
return x+n;
}
int dji(int x,int k){
    int ahaha=n+m+10;
    int d[ahaha],vis[ahaha]={};
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    memset(d,0x3f,sizeof(d));
    d[x]=0;
    q.push(make_pair(0,x));
    while(!q.empty()){
        auto tt=q.top();
        q.pop();
        int u=tt.second;
        if(vis[u])continue;
        vis[u]=1;
        for(int i=p[u];i;i=e[i].nxt){
            int v=e[i].v,w=e[i].w;
             if(d[u]+w<d[v]){
                d[v]=d[u]+w;
                q.push(make_pair(d[v],v));
            }
        }
    }
    return d[k];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>dd>>qq;
    for(int i=1;i<=m;i++){
        cin>>w[i];

    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            init(idsub(i),idting(a),t);
            init(idting(a),idsub(i),t);
        }
    }
    for(int i=1;i<=qq;i++){
        int x,r;cin>>x>>r;
        cout<<w[x]+w[r]+dji(idting(x),idting(r))<<"\n";
    }
    return 0;
}/*
0 2 5 20 2
 4 1 9 2 5
 3 1 5 2 7 4 6
 3 2 3 3 4 5 7
 1 3
 1 2
 */
