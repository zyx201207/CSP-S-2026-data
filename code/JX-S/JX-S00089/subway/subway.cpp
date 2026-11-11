#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5;
long long w[M],a[M][M],t[M][M],cross[M][25];
long long c,n,m,d,q,k,x,y,ans=0;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
    for(int i=1;i<=n;i++){
        scanf("%lld",&k);
        for(int j=1;j<=2*k;j++){
            scanf("%lld%lld",&a[i][j],&t[i][j]);
            for(int v=1;v<=25;v++)if(cross[a[i][j]][v]==0)cross[a[i][j]][v]=i;
        }
    }
    while(q--){
        scanf("%lld%lld",&x,&y);
        for(int i=1;i<=k;i++){
            a
        }
    }
}
