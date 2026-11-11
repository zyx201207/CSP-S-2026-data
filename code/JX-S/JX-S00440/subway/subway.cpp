#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int INF=1e9+10;
int c,n,m,d,q;
int k[N],a[510][N],t[510][N];
int s[N][N][510];
int w[N],ans;
void dfs(int x,int y,int z){
    if(x==y){
        ans=min(ans,z);
        return;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            z+=s[x][i][j];
            dfs(i,y,z);
            z-=s[x][i][j];
            dfs(x,y,z);
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.in","w",stdout);
    memset(s,INF,sizeof(s));
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++) scanf("%d",&w[i]);
    for(int i=1;i<=n;i++){
        scanf("%d",k[i]);
        for(int j=1;j<=k[i];j++){
            scanf("%d%d",&a[i][j],&t[i][j]);
        }
        for(int j=1;j<k[i];j++){
            s[a[i][j]][a[i][j+1]][i]=t[i][j+1];
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        dfs(x,y,z);
        printf("%lld\n",ans);
    }
    return 0;
}
