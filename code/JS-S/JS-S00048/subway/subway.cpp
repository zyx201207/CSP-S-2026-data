#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int slove(){
    dfs();
}
int dfs(){


}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&k[i]);
        for(int j=1;j<=k[i];j++){
            scanf("%d%d",&a[i]][j],&t[i][j]);
        }
    }
    for(int i=1;i<=q;i++){
        scanf("%d%d",&x,&y);
        slove();
    }


    return 0;
}
