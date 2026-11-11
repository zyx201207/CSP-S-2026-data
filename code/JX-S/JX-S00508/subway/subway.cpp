#include<bits/stdc++.h>
#define reg register
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    reg int c,n,m,d,q;
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    vector<int> w(m+1);
    vector<int> x(n+1);
    for(reg int i=1;i<=m;i++)
        scanf("%d",&w[i]);
    int xian[n+1][m+1];
    memset(xian,0,sizeof xian);
    for(reg int i=1;i<=n;i++){
        scanf("%d",&x[i]);
        for(reg int j=1;j<=x[i];j++)
            scanf("%d",xian[i][j]);
    }
    int dist[n+1][n+1];
    memset(dist,0x3f3f3f3f,sizeof dist);
    for(reg int i=1;i<=n;i++)
        for(reg int j=i+1;j<=n;j++)
            for(reg int k=1;k<=m;k++)
                if(xian[i][k]!=0&&xian[j][k]!=0)
                    dist[i][j]=min(dist[i][j],xian[i][k]+xian[j][k]);
    for(reg int i=1;i<=n;i++)
        for(reg int j=1;j<=x[i];j++)
    while(q--){
        reg int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",w[x]+w[y]);
    }
    return 0;
}
