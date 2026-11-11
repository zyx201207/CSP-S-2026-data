#include<bits/stdc++.h>
using namespace std;
const int M = 505;
const int N = 5e5 + 5;
long long c,n,m,d,q,jl[M][M],w[N],a,t,u,v,ans,k;

vector<pair<long long,long long> >G[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(i==j)continue;
            jl[i][j] = 1e18;
        }
    }
    for(int i = 1;i<=m;i++){
        scanf("%lld",&w[i]);
    }
    for(int i = 1;i<=n;i++){
        scanf("%lld",&k);
        while(k--){
            scanf("%lld%lld",&a,&t);
            G[a].push_back(make_pair(i,t));
        }
    }
    for(int i = 1;i<=m;i++){
        for(auto x:G[i]){
            for(auto y:G[i]){
                jl[x.first][y.first] = min(jl[x.first][y.first],x.second + y.second);
                jl[y.first][x.first] = min(jl[y.first][x.first],x.second + y.second);
            }
        }
    }
    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = i+1;j<=n;j++){
                if(i==k||j==k)continue;
                jl[i][j] = jl[j][i] = min(jl[i][j],jl[i][k] + jl[k][j]);
            }
        }
    }
    while(q--){
        scanf("%lld%lld",&u,&v);
        ans = 1e18;
        for(auto x:G[u]){
            for(auto y:G[v]){
                ans = min(ans,jl[x.first][y.first]+x.second+y.second+w[u]+w[v]);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
