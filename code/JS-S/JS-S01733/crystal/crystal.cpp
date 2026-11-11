#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,ans=0;
    cin>>n>>m;
    long long a[n+5];
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long b[n+5][n+5];
    for(long long i=1;i<=n;i++)
    {
        long long m1=m;
        for(long long j=i;j>=1;j--)
        {
            b[i][j]=a[i]-a[j];
        }
        long long num=1;
        while(m1>=0 && num<=i)
        {
            m1-=b[i][num];
            num++;
        }
        ans=max(num-1,ans);
    }
    cout<<ans;
    return 0;
}
