#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();
    return x*f;
}
typedef long long ll;
typedef pair<int,int> pii;
const int M=505;
const ll INF=0x3f3f3f3f3f3f3f3f;
int V[N],WB[N],nxt[N],tot,head[N];
void add(int u,int v,int w){
    nxt[++tot]=head[u];
    V[tot]=v;
    WB[tot]=w;
    head[u]=tot;
}
ll dis[M][M];
int T,n,m,d,q;
int W[N];
void getmin(ll &x,ll y){
    if(x>y) x=y;
}
void bulid(int x){
    for(int i=head[x];i!=-1;i=nxt[i]){
        for(int j=head[x];j!=-1;j=nxt[j]){
            int u=V[i],v=V[j],w=WB[i]+WB[j];
            getmin(dis[u][v],1ll*w);
            getmin(dis[v][u],1ll*w);
        }
    }
}
void Floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                getmin(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(head,-1,sizeof head);
    T=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++){
        W[i]=read();
    }
    for(int i=1;i<=n;i++){
        int k=read();
        while(k--){
            int x=read(),w=read();
            add(x,i,w);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            dis[i][j]=INF;
        }
    }
    for(int i=1;i<=m;i++){
        bulid(i);
    }
    Floyd();
    while(q--){
        int u=read(),v=read();
        ll ans=INF;
        for(int i=head[u];i!=-1;i=nxt[i]){
            int au=V[i],wa=WB[i];
            for(int j=head[v];j!=-1;j=nxt[j]){
                int av=V[j],wb=WB[j];
                getmin(ans,dis[au][av]+wa+wb);
            }
        }
        printf("%lld\n",ans+W[u]+W[v]);
    }
    return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
