#include<bits/stdc++.h>
using namespace std;
int n,m,c,d,q;
long long w[505050],s[505050][25],floyed[505][505];
int f[505050][25];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(floyed,0x3f,sizeof floyed);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i = 1;i<=n;i++) floyed[i][i] = 0;
    for(int i = 1;i<=m;i++) scanf("%lld",&w[i]);
    for(int i = 1;i<=n;i++){
        int k;scanf("%d",&k);
        for(int j = 1;j<=k;j++){
            int a;long long t;
            scanf("%d%lld",&a,&t);
            f[a][++f[a][0]] = i,s[a][++s[a][0]] = t;
        }
    }for(int i = 1;i<=m;i++){
        for(int j = 1;j<=f[i][0];j++){
            for(int k = j+1;k<=f[i][0];k++){
                floyed[f[i][k]][f[i][j]] = floyed[f[i][j]][f[i][k]] = min(floyed[f[i][j]][f[i][k]],s[i][j]+s[i][k]);
            }
        }
    }for(int k = 1;k<=n;k++) for(int i = 1;i<=n;i++) for(int j = 1;j<=n;j++) floyed[i][j] = min(floyed[i][j],floyed[i][k]+floyed[k][j]);
    while(q--){
        long long ans = 0x3f3f3f3f3f3f3f3f;
        int x,y;scanf("%d%d",&x,&y);
        for(int i = 1;i<=f[x][0];i++) for(int j = 1;j<=f[y][0];j++) ans = min(ans,floyed[f[x][i]][f[y][j]]+s[x][i]+s[y][j]);
        printf("%lld\n",ans+w[x]+w[y]);
    }
    return 0;
}
