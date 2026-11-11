#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,k,ans,x,y;
long long kou[1005];
long long road[1005][1005],al[1005],tl[1005];
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
cin>>c>>n>>m>>d>>q;
    for(int i = 0;i < 1000;i++){
        for(int j = 0;j < 1000;j++)road[i][j] = 1<<30;
        road[i][i] = 0;
    }
    for(int i = 1;i <= m;i++)scanf("%lld",&kou[i]);
    for(int i = 1;i <= n;i++){
        scanf("%lld",&k);
        for(int j = 1;j <= k;j++){
            scanf("%lld%lld",&al[j],&tl[j]);
        }
        for(int j = 1;j <= k-1;j++){
            for(int l = j+1;l <= k;l++){
                road[al[j]][al[l]] = min(tl[j]+tl[l],road[al[j]][al[l]]);
                road[al[l]][al[j]] = min(tl[j]+tl[l],road[al[l]][al[j]]);
            }
        }
    }
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= m;j++){
            for(int k = 1;k <= m;k++){
                road[i][j] = min(road[i][j],road[i][k]+road[k][j]);
            }
        }
    }
    for(int i = 1;i <= q;i++){
        scanf("%lld%lld",&x,&y);
        cout<<kou[x]+kou[y]+road[x][y]<<"\n";
    }

    return 0;
}
