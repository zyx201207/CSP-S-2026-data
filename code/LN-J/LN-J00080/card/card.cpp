#include<climits>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
signed int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    signed long long int L(0),n(0),J(0),z(0),j(8),l(0),m,i,k;
    scanf("%lld%lld",&n,&m);
    signed long long int a[n+9],w[m+9]={},ans[m+9]={},s[n+9];
    for(i=1;i<=n;++i)
        scanf("%lld",a+i);
    for(i=1;i<=n;++i)
    {
        memset(s,0,sizeof(s));
        memset(w,0,sizeof(w));
        k=0;
        for(j=i;j<=n;++j)
        {
            if(!w[a[j]])
            {
                s[++k]=a[j];
                w[a[j]]=k;
            }
            else
            {
                l=w[a[j]]-1;
                memset(s+w[a[j]],0,sizeof(s));
                w[a[j]]=0;
                k=l;
                s[++k]=a[j];
                w[a[j]]=k;
            }
        }
        for(L=1;L<=k;++L)
            ++ans[s[L]];
    }
    for(i=1;i<=m;++i)
        printf("%lld ",ans[i]);
    return 0;
}
