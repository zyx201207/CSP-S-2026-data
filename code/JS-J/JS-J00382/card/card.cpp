#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],ans[300005],in[300005];
int s[500005],top=0;
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    scanf("%lld%lld",&n,&m);
    bool f=1;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",a+i);
        f&=(a[i]>=a[i-1]);
    }
    if(f)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]!=a[i+1])
            {
                ans[a[i]]=i;
            }
        }
        for(int i=1;i<=m;i++)printf("%lld ",ans[i]);
        printf("\n");
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        memset(in,0,sizeof(in));
        top=0;
        for(int j=i;j<=n;j++)
        {
            while(in[a[j]]&&top>0&&s[top]!=a[j])in[s[top--]]=0;
            if(!in[a[j]])s[++top]=a[j],in[a[j]]=1;
        }
        for(int j=1;j<=m;j++)
        {
            ans[j]+=in[j];
        }
    }
    for(int i=1;i<=m;i++)printf("%lld ",ans[i]);
    printf("\n");
    return 0;
}
