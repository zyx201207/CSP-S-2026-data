#include<bits/stdc++.h>
using namespace std;
const int N=500005,K=505;
const long long X=1LL<<61;
int c,n,m,d,q;
long long w[N],D[K][K];
vector<pair<int,int>>g[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%lld",w+i);
    }
    for(int i=1,k;i<=m;i++){
        scanf("%d",&k);
        for(int j=0,a,t;j<k;j++){
            scanf("%d%d",&a,&t);
            g[a].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            D[i][j]=i==j?0:X;
        }
    }
    for(int v=1;v<=m;v++){
        for(auto&p:g[v]){
            for(auto&r:g[v]){
                D[p.first][r.first]=min(D[p.first][r.first],(long long)p.second+r.second);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                D[i][j]=min(D[i][j],D[k][i]+D[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        long long r=X;
        for(auto&p:g[x]){
            for(auto&t:g[y]){
                r=min(r,p.second+D[p.first][t.first]+t.second);
            }
        }

        printf("%lld\n",(long long)w[x]+w[y]+r);
    }
    return 0;
}
