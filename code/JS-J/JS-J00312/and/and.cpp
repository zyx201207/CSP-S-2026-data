#include <bits/stdc++.h>
using namespace std ;
int n,m;
long long a[200005],c[200005],f[10005][10005],ans=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
        f[i][1]=a[i];
    for(int i=m;i<=n;i++)
        for(int j=2;j<=m;j++)
            for(int k=1;k<i;k++)
                f[i][j]=max(f[i][j],f[k][j-1]&a[i]);
    for(int i=1;i<=n;i++)
        ans=max(ans,f[i][m]);
    printf("%lld\n",ans);
    return 0;
}
