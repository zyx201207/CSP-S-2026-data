#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll c,n,m,d,q,w[510000],k[550];
vector<ll> a[550],t[550];

ll f[550][550];

// vector<int> dt[510000]; // 第i个地铁站的停靠的车
// int xj[550][550][1100]; // 第i个地铁与第j个地铁相交的站k

void Print(){
    for(int i = 1; i<=m; ++i){
        for(int j = 1; j<=m; ++j){
            printf("%lld ",f[i][j]);
        } printf("\n");
    }printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i = 1; i<=m; ++i){
        scanf("%lld",&w[i]);
    }
    for(int i = 1; i<=n; ++i){
        scanf("%lld",&k[i]);
        for(int j = 1; j<=k[i]; ++j){
            int aik,tik;
            scanf("%lld%lld",&aik,&tik);
            a[i].push_back(aik);
            t[i].push_back(tik);
        }
    }

    memset(f,0x3f,sizeof f);
    for(int l = 1; l<=n; ++l){
        for(int i = 0; i<k[l]; ++i)
            for(int j = i+1; j<k[l]; ++j)
                f[a[l][i]][a[l][j]] = min(f[a[l][i]][a[l][j]],t[l][i]+t[l][j]),
                f[a[l][j]][a[l][i]] = min(f[a[l][i]][a[l][j]],t[l][i]+t[l][j]);
    }
    // Print();
    for(int l = 1; l<=m; ++l){
        for(int i = 1; i<=m; ++i)
            for(int j = 1; j<=m; ++j)
                if(f[i][l] < 0x3f3f3f3f3f3f3f3f && f[l][j] < 0x3f3f3f3f3f3f3f3f){
                    f[i][j] = min(f[i][j],f[i][l]+f[l][j]);
                }
    }
    // Print();

    for(int i = 1; i<=q; ++i){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%lld\n",w[x]+w[y]+f[x][y]);
    }
    return 0;
}
