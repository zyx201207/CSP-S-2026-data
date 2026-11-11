#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
using _int=long long;
const int s=1000000;
_int c,m,n,d,q,tot;
int w[s],hed[s],nxt[s],ver[s],edg[s];
_int dis[s];
void add(_int x,_int y,_int z){
    ver[++tot]=y,edg[tot]=z,nxt[tot]=hed[x],hed[x]=tot;
}
_int calc(_int x,_int y){
    queue<_int> qu;
    qu.push(x);
    memset(dis,0x3f,sizeof(dis));
    dis[x]=0;
    while(qu.size()){
        int u=qu.front();
        qu.pop();
        for(int i=hed[u];i;i=nxt[i]){
            int v=ver[i],val=edg[i];
            if(dis[v]>dis[u]+val){
                dis[v]=dis[u]+val;
                qu.push(v);
            }
        }

    }
    return dis[y];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    _int k;
    for(int i=1;i<=n;i++){
        scanf("%lld",&k);
        for(int j=1;j<=k;j++){
            int a,t;
            scanf("%d%d",&a,&t);
            add(a,i+m,t);
            add(i+m,a,t);
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%lld\n",calc(x,y)+w[x]+w[y]);
    }
    return 0;
}
