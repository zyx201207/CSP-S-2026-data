#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
const int N=5e5+5,M=505,K=1e5;
int m,w[N],n,d,k[M],a[M][M],t[M][M],q,x,y;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>n>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&k[i]);
        for(int j=1;j<=k[i];j++){
            scanf("%d%d",&a[i][j],&t[i][j]);
        }
    }
    cin>>q;
    while(q--){
        cin>>x>>y;

    }
    return 0;
}
