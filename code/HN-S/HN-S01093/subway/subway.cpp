#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define fi first
#define se second
#define pb push_back
#define v(x) vector<x>
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const ll inf=0x3f3f3f3f3f3f3f3f;
const int N=500010;
int ID,n,m,d,q;
int w[N];
v(pii)sb[N];
ll eg[510][510];
void minn(ll&a,ll b){
    if(b<a) a=b;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&ID,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    for(int k,i=1;i<=n;i++){
        scanf("%d",&k);
        for(int j=0;j<k;j++){
            int st,tm;
            scanf("%d%d",&st,&tm);
            sb[st].pb({i,tm});
        }
    }
    memset(eg,0x3f,sizeof(eg));
    for(int i=1;i<=m;i++){
        int sz=sb[i].size();
        for(int j=0;j<sz;j++){
            for(int k=j+1;k<sz;k++){
                minn(eg[sb[i][j].fi][sb[i][k].fi],sb[i][j].se+sb[i][k].se);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            ll mn=min(eg[i][j],eg[j][i]);
            eg[i][j]=eg[j][i]=mn;
        }
        eg[i][i]=0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                minn(eg[i][j],eg[i][k]+eg[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        ll ans=inf;
        for(pii a:sb[x]){
            for(pii b:sb[y]){
                minn(ans,a.se+b.se+eg[a.fi][b.fi]);
            }
        }
        ans+=w[x]+w[y];
        printf("%lld\n",ans);
    }
    return 0;
}