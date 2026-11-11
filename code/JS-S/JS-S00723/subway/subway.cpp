#include <bits/stdc++.h>
using namespace std;
#define int long long

int c,n,m,d,q;
struct Subway{
    int i,t;
};

vector <Subway> v[500010];
int g[510][510];
int w[500010];
map <pair <int,int> ,int> ma;

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j){
                g[i][j]=1e18;
            }
        }
    }
    for(int i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }
    for(int i=1,k;i<=n;i++){
        cin>>k;
        for(int j=1,a,t;j<=k;j++){
            scanf("%lld%lld",&a,&t);
            for(auto e : v[a]){
                g[e.i][i]=min(g[e.i][i],e.t+t);
                g[i][e.i]=g[e.i][i];
            }
            v[a].push_back({i,t});
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j){
                    g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
                }
            }
        }
    }
    while(q--){
        int s,t,ans=1e18;
        scanf("%lld%lld",&s,&t);
        if(ma[{s,t}]!=0){
            printf("%lld\n",ma[{s,t}]);
        }
        for(auto e1 : v[s]){
            for(auto e2 : v[t]){
                ans=min(ans,g[e1.i][e2.i]+e1.t+e2.t);
            }
        }
        ma[{s,t}]=ans+w[s]+w[t];
        printf("%lld\n",ans+w[s]+w[t]);
    }
    return 0;
}
