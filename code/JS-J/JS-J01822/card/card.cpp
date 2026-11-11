#include<bits/stdc++.h>
using namespace std;
long long arr[500007];
long long sy[500007];
long long  ans[500007];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i = 1;i<=n;i++)
    {
        cin>>arr[i];
    }
    for(long long  i = 1;i<=n;i++)
    {
        for(long long  j = 1;j<=n;j++)
        {
            sy[j] = 0;
        }
        long long t = 1;
        for(long long j = 1+i-1;j<=n;j++)
        {
            sy[t] = arr[j];
            for(long long  k = 1;k<=t;k++)
            {
                if(sy[t]==sy[k])
                {
                    for(long long  a = k+1;a<=t;a++)
                    {
                        sy[a] = 0;
                    }
                }
            }
            t++;
        }
        for(long long  j = 1;j<=n;j++)
        {
            if(sy[j]!=0)
            {
                ans[sy[j]]++;
            }
        }
    }
    for(long long  i = 1;i<=m;i++)
    {
        cout<<ans[i]<<' ';
    }
    return 0;
}
