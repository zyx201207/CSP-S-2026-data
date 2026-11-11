#include<bits/stdc++.h>
#define Mp(x,y) make_pair(x,y)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int N = 507,M = 5e5+7;
int C,n,m,d,q,w[M];ll f[N][N];
vector<pii> v[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&C,&n,&m,&d,&q);
    for(int i = 1;i <= m;i++) scanf("%d",&w[i]);
    memset(f,0x3f,sizeof f);
    for(int i = 1,k;i <= n;i++){
        f[i][i] = 0;scanf("%d",&k);
        for(int j = 1,p,t;j <= k;j++){
            scanf("%d%d",&p,&t);
            v[p].push_back(Mp(i,t));
        }
    }
    for(int i = 1;i <= m;i++){
        for(int j = 0;j < (int)v[i].size();j++)
        for(int k = 0;k < j;k++){
            int a = v[i][j].first,b = v[i][k].first;
            f[a][b] = f[b][a] = min(f[a][b],(ll)v[i][j].second+v[i][k].second);
        }
    }
    for(int i = 1;i <= n;i++)
    for(int j = 1;j <= n;j++)
    for(int k = 1;k <= n;k++)
        f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
    while(q--){
        int x,y;ll ans = 1e18;
        scanf("%d%d",&x,&y);
        if(x == y){puts("0");continue;}
        for(const auto &tx:v[x])
        for(const auto &ty:v[y])
            ans = min(ans,tx.second+ty.second+f[tx.first][ty.first]);
        printf("%lld\n",ans+w[x]+w[y]);
    }
    return 0;
}
