#include<bits/stdc++.h>
using namespace std;
struct nom{
    int to,linee;
};
int c,n,m,d,q,an=0;
int a[50009][5009],w[50009],t[50009][5009],k[50009],y;
bool tf[50009];
vector<nom> edg[50009];
void dfs(int now,int lin,int tim){
    if(now==y){
        an=min(an,tim);
        return;
    }
    for(auto nex:edg[now]){
        if(!tf[nex.to]){
            int mony=0;
            tf[nex.to]=1;
            if(lin!=0){
                mony+=t[lin][now];
            }
            mony+=t[nex.linee][now];
            dfs(nex.to,nex.linee,tim+mony);
            tf[nex.to]=0;
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&k[i]);
        for(int j=1;j<=k[i];j++){
            scanf("%d%d",&a[i][j],&t[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k[i];j++){
            for(int kk=j+1;kk<=k[i];kk++){
                nom EDG;
                EDG.to=kk;EDG.linee=i;
                edg[a[i][j]].push_back(EDG);
            }
        }
    }
    //printf("%d%d%d%d%d",c,n,m,d,q);
    for(int i=1;i<=q;i++){
        int x,ans=w[x]+w[y];
        scanf("%d%d",&x,&y);
        an=0;
        memset(tf,0,sizeof(tf));
        dfs(x,0,0);
        tf[x]=1;
        printf("%d\n",an+ans);
    }
    return 0;
}
