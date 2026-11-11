#include<bits/stdc++.h>
using namespace std;
const int maxn=500+10,maxd=20+10,maxq=1e5+100,maxkh=5e5+100,maxm=maxkh;
int c,n,m,d,q,w[maxm],a[maxn][maxkh],t[maxn][maxkh],x[maxq],y[maxq],k[maxn];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++) scanf("%d",&w[i]);
    for(int i=1;i<=n;i++){
        scanf("%d",&k[i]);
        for(int j=1;j<=k[i];j++)
            scanf("%d %d",&a[i][j],&t[i][j]);
    }
    for(int i=1;i<=q;i++) scanf("%d %d",&x[i],&y[i]);

    return 0;
}
