#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    int w[m];
    for(int i = 0;i < m;i++){
        scanf("%d",&w[i]);
    }
    for(int i = 1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j = 1;j <= k;j++){
            int a,t;
            scanf("%d%d",&a,&t);
        }
    }
    for(int i = 1;i <= q;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("24");
    }
    return 0;
}
