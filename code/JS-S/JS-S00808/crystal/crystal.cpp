#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        long long sum=1,f=m;
        for(int j=i-1;j>=1;j--)
        {
            if(f>=(i-j))
            {
                f-=(i-j);
                sum++;
            }
            else break;
        }
        ans=max(ans,sum);
    }
    cout<<ans;
    return 0;
}
