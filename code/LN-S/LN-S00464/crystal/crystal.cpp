#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];

    }
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++)
    {
        for(long long j=0;j<=m;j++)
        {
            if(a[i]+j==a[i+1])
            {
                m-=j;
                a[i]+=j;
            }

        }
    }

    sum=0;
    for(long long i=2;i<=n;i++)
    {
        if(a[i]==a[i-1])
        {
            sum++;
        }
    }
    cout<<sum+1;
    return 0;
}
