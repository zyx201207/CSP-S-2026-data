#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int n,m,c,d,q,ans,w[MAXN],k[MAXN],a[MAXN][MAXN],t[MAXN][MAXN],x[MAXN],y[MAXN];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i = 1;i <= m;i++) scanf("%d",&w[i]);
    for(int i = 1;i <= 2;i++){
        scanf("%d",&k[i]);
        for(int j = 1;j <= k[i];j++) scanf("%d%d",&a[i][j],&t[i][j]);
    }
    for(int i = 1;i <= q;i++) scanf("%d%d",&x[i],&y[i]);
    for(int i = 1;i <= q;i++){
        for(int f = 1;f <= n;f++){
            for(int j = 1;j <= 2;j++){
                for(int b = 1;b <= k[i];b++)
                    ans = w[f] + t[i][b] + (t[i][b] + t[j][b]) + t[b][f] + w[i];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
