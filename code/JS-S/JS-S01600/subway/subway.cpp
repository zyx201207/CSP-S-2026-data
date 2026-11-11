#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct N{
    ll a,t;
};
ll c,n,m,d,q,w[505],k[505],f[1004][1004];
vector<N>v[505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)scanf("%lld",w+i);
    for(int i=1;i<=m;i++){
        for(int j=i+1;j<=m;j++){
            f[i][j]=f[j][i]=0x3f3f3f3f3f3f3f3f;
        }
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",k+i);
        for(int j=0;j<k[i];j++){
            ll a,t;
            scanf("%lld%lld",&a,&t);
            v[i].push_back({a,t});
        }
        for(int j=0;j<k[i];j++){
            for(int ii=j+1;ii<k[i];ii++){
                f[v[i][j].a][v[i][ii].a]=f[v[i][ii].a][v[i][j].a]=v[i][j].t+v[i][ii].t;
            }
        }
    }
    for(int p=1;p<=m;p++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                f[i][j]=min(f[i][j],f[i][p]+f[p][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        ll s,e;
        scanf("%lld%lld",&s,&e);
        printf("%lld\n",f[s][e]+w[s]+w[e]);
    }
    return 0;
}
