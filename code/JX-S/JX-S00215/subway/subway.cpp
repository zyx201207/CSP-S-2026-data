#include <bits/stdc++.h>
using namespace std;
const int N=500525;
const int M=100255;
int m,n,d,q,c,w[N],k[N],a[505][M],t[505][M];
long long ans[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
        //从第v(1≤v≤m)个地铁站的地铁口走到站厅需要w[v]的时间。
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&k[i]);
        for(int j=1;j<=k[i]){
            scanf("%d%d",&a[i][j],&t[i][j]);
//在第a[i]个地铁站处，从站厅走到第i条线路的站台需要t[i][j]的时间
        }
    }
    for(int r=1;r<=q;i++){
        scanf("%d%d",&x[r],y[r]);
        if(c>=7&&c<=11){
            ans[r]+=w[x[r]]+t[x[r]][x[r]]+t[x[r]][y[r]]+w[y];
            printf("%lld",ans[r]);
        }
    }
    return 0;
}

