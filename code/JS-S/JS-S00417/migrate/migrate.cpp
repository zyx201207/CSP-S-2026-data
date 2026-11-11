#include<bits/stdc++.h>
using namespace std;
const int N = 16301;
int c,t;
int n,ans,dist[N][N],s[N][N];
long long d,x[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while (t--){
        memset(dist,0x3f,sizeof(dist));
        memset(s,0,sizeof(s));
        scanf("%d%lld",&n,&d);
        int now = 1;
        for (int i = 1;i <= n;i++) {
            scanf("%lld",&x[i]);
            for (int j = now;j < i;j++){
                if (x[i] - now <= d){
                    dist[j][i] = 1;
                    dist[i][j] = 1;
                }
                else now++;
            }
        }
        for (int k = 1;k <= n;k++)
            for (int i = 1;i <= n;i++)
                for (int j = 1;j <= n;j++){
                    if (dist[i][k] + dist[k][j] < dist[i][j]){
                        dist[i][j] = dist[i][k]+dist[k][j];
                        s[i][j] = 0;
                    }
                    else if (dist[i][k] + dist[k][j] == dist[i][j]) s[i][j]++;
                }
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= n;j++)
                if (s[i][j] == 2) ans++;
        printf("%d\n",ans/2);
    }
    return 0;
}
