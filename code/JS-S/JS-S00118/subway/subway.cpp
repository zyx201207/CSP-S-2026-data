#include<cstdio>
#include<algorithm>
constexpr int N=5e2+5,M=5e3+5;
int c,n,m,d,q,w[M],k[N],a[N][M],t[N][M],s[M][M],x,y;
unsigned int Min;
bool vis[M];
void dfs(int pos,unsigned int cost){
    vis[pos]=true;
    if(pos==y)Min=std::min(Min,cost);
    for(int i=1;i<=m;++i)
        if((!vis[i])&&(s[pos][i]))
            dfs(i,cost+s[pos][i]);
    vis[pos]=false;
}int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    setvbuf(stdin,NULL,_IOFBF,1<<22);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;++i)scanf("%d",&w[i]);
    for(int i=1;i<=n;++i){
        scanf("%d",&k[i]);
        for(int j=1;j<=k[i];++j){
            scanf("%d%d",&a[i][j],&t[i][j]);
            for(int _=1;_<j;++_)s[a[i][_]][a[i][j]]=t[i][_]+t[i][j];
        }
    }do{
        scanf("%d%d",&x,&y);
        Min=-1;
        dfs(x,0);
        printf("%d\n",Min+w[x]+w[y]);
    }while(--q);
    return 0;
}
