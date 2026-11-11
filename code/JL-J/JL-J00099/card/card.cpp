#include<bits/stdc++.h>
using namespace std;
const int inf = 3e6+10;
int a[inf],sum[inf],n,m,x;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    sum[0] = 0;
    a[0] = 0;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        a[x]++;
    } for(int i=1;i<=m;i++){
        sum[i] = sum[i-1] + a[i];
    } for(int i=1;i<=m;i++){
        printf("%d ",sum[i]);
    } printf("\n");
    return 0;
}
