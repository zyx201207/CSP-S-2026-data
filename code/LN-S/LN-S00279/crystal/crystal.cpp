#include<bits/stdc++.h>
using namespace std;
int m,n,d1,m1,a[500005],ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d %d",&n,&m);
    m1=m;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++)
    {
        for(int j=i-1;j>=1&&m1>0;j--)
        {
            if(m1<a[i]-a[j]) break;
            else
            {
            m1-=a[i]-a[j];
            d1++;
            }
        }
        m1=m;
        ans=max(d1,ans);
        d1=0;
    }
    ans++;
    printf("%d",ans);
    return 0;
}
