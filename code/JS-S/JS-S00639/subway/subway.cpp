#include<bits/stdc++.h>
#define Maxn 200
using namespace std;
void free(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
}
int c,n,m,d,q,G[210][410];
int x,y,ans,t;
bool k[210];
void dfs(int lu,int now_w,int zong){
    if(now_w==G[lu][0]&&zong==0)return;
    if(now_w==G[lu][0]&&G[lu][(now_w-1)*2+1]!=y)return;
    if(zong==0)dfs(lu,now_w+1,G[lu][now_w*2]);
    if(G[lu][(now_w-1)*2+1]==y){
        t=min(t,zong);
        return;
    }
    if(k[lu]&&now_w!=G[lu][0])dfs(lu,now_w+1,zong);
    else{
        dfs(lu,now_w+1,zong);
        for(int i=1;i<=n;i++){
            if(k[i])for(int j=1;j<=G[i][0];j++){
                if(G[i][(j-1)*2+1]==G[lu][(now_w-1)*2+1])dfs(i,j,zong+G[lu][now_w*2]+G[i][j*2]);
            }
        }
    }
}
int main(){
    free();
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
        scanf("%d",&G[0][i]);
    for(int i=1;i<=n;i++){
        scanf("%d",&G[i][0]);
        for(int j=1;j<=G[i][0];j++)
            scanf("%d%d",&G[i][(j-1)*2+1],&G[i][j*2]);
    }
    for(int i=1;i<=q;i++){
        scanf("%d%d",&x,&y);
        memset(k,false,sizeof(k));
        for(int j=1;j<=n;j++){
            for(int z=1;z<=G[j][0];z++){
                if(G[j][(z-1)*2+1]==y){
                    k[j]=true;
                }
            }
        }
        ans=G[0][x]+G[0][y];t=0x3f3f3f3f;
        for(int j=1;j<=n;j++){
            for(int z=1;z<=G[j][0];z++){
                if(G[j][(z-1)*2+1]==x){
                    dfs(j,z,0);
                }
            }
        }
        ans+=t;
        printf("%d\n",ans);
    }
    return 0;
}
