#include <bits/stdc++.h>
#define ll long long 
#define sc scanf 
#define pr printf
#define v1 first 
#define v2 second 
#define IINF 0x3f3f3f3f 
#define INF 0x3f3f3f3f3f3f3f3fll
using namespace std;
const int N=505,M=5e5+5;
int w[M];
vector<pair<int,int>> v[M];
ll dis[N][N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int _,n,m,q,d;
    sc("%d%d%d%d%d",&_,&n,&m,&d,&q);
    for(int i=1; i <= m; i++)sc("%d",&w[i]);
    for(int i=1; i <= n; i++){
        int k;sc("%d",&k);
        for(int j=1,x,y; j <= k; j++){
            sc("%d%d",&x,&y);
            v[x].push_back({i,y});
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1; i <= n; i++)dis[i][i]=0;
    for(int i=1; i <= m; i++){
        for(auto x:v[i]){
            for(auto y:v[i]){
                dis[x.v1][y.v1]=min(dis[x.v1][y.v1],(ll)x.v2+y.v2);
            }
        }
    }
    for(int i=1; i <= n; i++){
        for(int j=1; j <= n; j++){
            for(int k=1; k <= n; k++){
                if(dis[i][k]+dis[k][j]<dis[i][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
    }
    while(q--){
        int a,b;sc("%d%d",&a,&b);
        ll ans=INF;
        for(auto x:v[a]){
            for(auto y:v[b]){
                ans=min(ans,dis[x.v1][y.v1]+x.v2+y.v2);
            }
        }
        ans+=w[a];ans+=w[b];
        pr("%lld\n",ans);
    }
    return 0;
}