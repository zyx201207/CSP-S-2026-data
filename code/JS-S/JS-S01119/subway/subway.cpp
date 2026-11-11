#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int w[500010];
vector<int> a[500010];
int t[500010][510];
int dw[510][510];
int Ci,Cx,Cy;
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(dw,0x4f,sizeof(dw));
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i<=m;i++){
        scanf("%lld",&Ci);
        w[i] = Ci;
    }
    for(int i = 1;i<=n;i++){
        dw[i][i] = 0;
        scanf("%lld",&Ci);
        for(int j = 1;j<=Ci;j++){
            scanf("%lld%lld",&Cx,&Cy);
            a[Cx].push_back(i);
            t[Cx][i] = Cy;
        }
    }
    for(int i = 1;i<=m;i++){
        for(int j = 0;j<a[i].size();j++){
            for(int k = j+1;k<a[i].size();k++){
                dw[a[i][j]][a[i][k]] = min(dw[a[i][j]][a[i][k]],t[i][a[i][j]]+t[i][a[i][k]]);
                dw[a[i][k]][a[i][j]] = min(dw[a[i][j]][a[i][k]],t[i][a[i][j]]+t[i][a[i][k]]);
            }
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            for(int k = 1;k<=n;k++){
                if(i==j||j==k||i==k)continue;
                dw[i][k] = min(dw[i][k],dw[i][j]+dw[j][k]);
            }
        }
    }
    for(int i = 1;i<=n;i++){
        scanf("%lld%lld",&Cx,&Cy);
        int ans = 1e9;
        for(int j = 0;j<a[Cx].size();j++){
            for(int k = 0;k<a[Cy].size();k++){
                ans = min(ans,dw[a[Cx][j]][a[Cy][k]]+w[Cx]+w[Cy]+t[Cx][a[Cx][j]]+t[Cy][a[Cy][k]]);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
