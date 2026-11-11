#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm=5e5+10;
const int maxn=510;
#define fi first
#define se second
int w[maxm];
ll dis[maxn][maxn];
vector<pair<int,int>>D[maxm];
void chmin(ll &a, ll b){
    if(a>b)a=b;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    // cout<<"///////////\n";
    int c,n,m,d,q;
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++){
        dis[i][i]=0;
    }
    // cout<<"///////////\n";
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int a,t;
            scanf("%d%d",&a,&t);
            D[a].push_back(make_pair(i,t));
        }
    }
    // cout<<"///////////\n";
    for(int i=1;i<=m;i++){
        int siz=D[i].size();
        for(int j=0;j<siz;j++){
            for(int k=j+1;k<siz;k++){
                chmin(dis[D[i][j].fi][D[i][k].fi],(ll)D[i][j].se+D[i][k].se);
                chmin(dis[D[i][k].fi][D[i][j].fi],(ll)D[i][j].se+D[i][k].se);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            for(int k=1;k<=n;k++){
                chmin(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    // cout<<"///////////\n";
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        ll res=1e18;
        for(int i=0;i<D[x].size();i++){
            for(int j=0;j<D[y].size();j++){
                chmin(res,dis[D[x][i].fi][D[y][j].fi]+D[x][i].se+D[y][j].se);
            }
        }
        res+=w[x]+w[y];
        printf("%lld\n",res);
    }
    return 0;
}
/*
cat subway7.in > subway.in && time ./subway && diff subway.out subway7.ans -q -s
*/