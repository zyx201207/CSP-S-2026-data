#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<climits>
signed int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    signed long long int ln(0),s(0),z(1),j(4),l(0),c,n,m,d,q,x,y,i;
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    signed long long int t[m+9][9+m];
    if(n==1)
    {
        for(i=1;i<=m;++i)
            scanf("%lld",&t[i][i]);
        scanf("%*lld");
        for(i=1;i<=m;++i)
        {
            scanf("%*lld%lld",&x);
            t[i][i]+=x;
        }
        for(i=1;i<=m;++i)
            for(j=i+1;j<=m;++j)
                t[i][j]=t[j][i]=t[i][i]+t[j][j];
    }
    for(;q;--q)
    {
        scanf("%lld%lld",&x,&y);
        printf("%lld\n",t[x][y]);
    }
    return 0;
}
