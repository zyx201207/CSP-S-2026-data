#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,M=5e5+5;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll q_rd(){
    char c;
    ll res=0,f=1;
    c=getchar();
    while(c<'0'||'9'<c){
        if(c=='-')f=-1;
        c=getchar();
    }
    while('0'<=c&&c<='9'){
        res=(res<<3)+(res<<1)+c-48;
        c=getchar();
    }
    return f*res;
}
ll dis[N][N],G[N][N];
struct Node{
    int id;
    ll d;
    bool operator<(const Node &o)const{
        return d>o.d;
    }
};
ll c,n,m,d,q;
void dij(int s){
    priority_queue<Node> q;
    q.push({s,0});
    while(!q.empty()){
        Node u=q.top();
        q.pop();
        for(int v=1;v<=n;v++){
            ll w=G[u.id][v];
            if(dis[s][v]>dis[s][u.id]+w){
                dis[s][v]=dis[s][u.id]+w;
                q.push({v,dis[s][v]});
            }
        }
    }
    return;
}
ll t_out[M];
vector<Node> ins[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(G,0x3f,sizeof G);
    memset(dis,0x3f,sizeof dis);
    c=q_rd(),n=q_rd(),m=q_rd(),d=q_rd(),q=q_rd();
    for(int i=1;i<=m;i++)t_out[i]=q_rd();
    for(int i=1;i<=n;i++){
        ll k=q_rd();
        for(int j=1;j<=k;j++){
            ll pos=q_rd(),tim=q_rd();
            for(auto v:ins[pos]){
                G[i][v.id]=min(G[i][v.id],v.d+tim);
                G[v.id][i]=min(G[v.id][i],v.d+tim);
            }
            ins[pos].push_back({i,tim});
        }
    }
    for(int i=1;i<=n;i++)dis[i][i]=G[i][i]=0;
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            printf("%lld ",G[i][j]);
        printf("\n");
    }*/
    for(int i=1;i<=n;i++)dij(i);
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            printf("%lld ",dis[i][j]);
        printf("\n");
    }*/
    while(q--){
        ll s=q_rd(),t=q_rd();
        ll ans=INF;
        for(Node u:ins[s]){
            for(Node v:ins[t]){
                ans=min(ans,u.d+dis[u.id][v.id]+v.d);
            }
        }
        printf("%lld\n",ans+t_out[s]+t_out[t]);
    }
    return 0;
}
