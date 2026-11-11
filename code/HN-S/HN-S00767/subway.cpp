#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e2+10;
const int MAXN=6e5+10;
int n,m,d,q;
int w[N][N];
int a[MAXN];
struct Edge{
    int to,nxt,w;
}e[MAXN<<1];
int head[MAXN],tot;
void add(int x,int y,int w){
    e[++tot]={y,head[x],w};
    head[x]=tot;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>n>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        while(k--){
            int x,y;cin>>x>>y;
            add(i+m,x,y),add(x,i+m,y);
        }
    }
    memset(w,0x3f,sizeof(w));
    for(int i=1;i<=n;i++) w[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int j=head[i];j;j=e[j].nxt){
            int u=e[j].to-m,w1=e[j].w;
            for(int k=head[i];k;k=e[k].nxt){
               int v=e[k].to-m,w2=e[k].w;
               w[u][v]=w[v][u]=min(w[u][v],w1+w2);
            //    cout<<u<<' '<<v<<
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                w[i][j]=min(w[i][j],w[i][k]+w[k][j]);
            }
        }
    }
    while(q--){
        int u,v;cin>>u>>v;int rs=2e18;
        for(int i=head[u];i;i=e[i].nxt){
            for(int j=head[v];j;j=e[j].nxt){
                int x=e[i].to-m,y=e[j].to-m;
                // cout<<x<<' '<<y<<' '<<u<<' '<<v<<'\n';
                rs=min(rs,e[i].w+e[j].w+w[x][y]);
            }
        }cout<<rs+a[u]+a[v]<<'\n';
    }
    return 0;
}