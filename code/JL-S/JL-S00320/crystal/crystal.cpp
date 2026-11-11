#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5000005],maxx;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {

        long long cnt=m,num=1;
        for(int j=i-1;j>=1;j--)
        {
            if(a[i]-a[j]<=cnt)
            {
                cnt=cnt-(a[i]-a[j]);
                num++;
            }
            else if(a[i]-a[j]>cnt) break;
        }
        maxx=max(maxx,num);
    }

    printf("%lld",maxx);
    return 0;
}
