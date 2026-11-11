#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
using pil=pair<int,ll>;
const int N=5e5+5,M=505;
int c,n,m,d,q;
ll w[N];
vector<pil> xl[M];
vector<pii> pos[N];
// test 1-11
const int N1to8=505;
ll dis[N1to8][N1to8];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    // n,m is swaped
    scanf("%d%d%d%d%d",&c,&m,&n,&d,&q);
    for(int i=1;i<=n;i++) scanf("%lld",&w[i]);
    for(int i=1;i<=m;i++){
        int kk;
        scanf("%d",&kk);
        for(int j=0;j<kk;j++){
            int u;
            ll w;
            scanf("%d%lld",&u,&w);
            xl[i].push_back(make_pair(u,w));
            pos[u].push_back(make_pair(i,j));
        }
    }
    if(n<=600){
        // test 1-8:sum of k[i]<=400
        // test 9-11:a directionless graph,|E|<=500->|V|<=501
        // test 1-11 44pts
        // O(n^3) floyd
        memset(dis,0x3f,sizeof dis);
        for(int i=1;i<=m;i++){
            for(int j=0;j<(int)xl[i].size();j++){
                for(int jj=j+1;jj<(int)xl[i].size();jj++){
                    int posj=xl[i][j].first,posjj=xl[i][jj].first;
                    ll wj=xl[i][j].second,wjj=xl[i][jj].second;
                    dis[posjj][posj]=dis[posj][posjj]=min(dis[posj][posjj],wj+wjj);
                }
            }
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                if(i==k) continue;
                for(int j=1;j<=n;j++){
                    if(i==j||j==k) continue;
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
        while(q--){
            int x,y;
            scanf("%d%d",&x,&y);
            ll ans=w[x]+w[y];
            printf("%lld\n",ans+dis[x][y]);
        }
        return 0;
    }
    printf("0\n");
    return 0;
}
