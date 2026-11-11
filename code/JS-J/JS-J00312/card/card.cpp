#include <bits/stdc++.h>
using namespace std ;
int n,m,a[500005],ans[300005],last[300005],sum=0;
inline void play(int x){
    sum=x;
    while(sum<=n){
        ++ans[a[sum]];
        sum=last[a[sum]]+1;
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        last[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
        play(i);
    for(int i=1;i<=m;i++)
        printf("%d ",ans[i]);
    return 0;
}
