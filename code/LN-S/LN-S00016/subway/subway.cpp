#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std ;
const int N = 501;
const int M = 5e5+100;
const int INF = 0x3f3f3f3f;
int a[N][M] ;
int t[N][M] ;
int k[N];
int w[M];
long long dis[N][N];
vector <pair<int,int>> G[M];
long long c,n,m,d,q;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(dis,INF,sizeof dis);
    cin >> c >> n >> m >> d >> q ;
    for(int i = 1; i <= m ; i ++)
        scanf("%d",&w[i]);
    for(int i = 1 ; i <= n ; i ++){
        scanf("%d",&k[i]);
        for(int j = 1; j <= k[i] ; j ++){
            scanf("%d%d",&a[i][j],&t[i][j]);
            G[a[i][j]].push_back({i,t[i][j]});
        }
    }
    for(int i = 1 ; i <= m ; i ++){
        for(auto u : G[i]){
            for(auto v:G[i]){
                dis[u.first][v.first] = min(dis[u.first][v.first],(long long)v.second+(long long)u.second);
                if(u.first==v.first) dis[u.first][v.first] = 0 ;
            }
        }
    }
    for(int k = 1 ; k <= n ; k ++){
        for(int i = 1 ; i <= n ; i ++){
            for(int j = 1 ; j <= n ; j ++){
                if(i!=j&&i!=k&&j!=k)
                    dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        long long ans = 0x3f3f3f3f3f3f3f3f;
        for(auto u:G[x]){
            for(auto v:G[y]){
                ans = min(ans,(long long)u.second+(long long)v.second+dis[u.first][v.first]+(long long)w[x]+(long long)w[y]);
            }
        }
        printf("%lld\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0 ;
}
