#include<bits/stdc++.h>
using namespace std;
long long ans=INT_MAX;
long long a[200010];
long long n,m;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==m)
    {
        for(long long i=1;i<=n;i++)
        {
            ans=(ans&a[i]);
        }
    }
    else
    {
        if(m==1)
        {
            ans=INT_MIN;
            for(long long i=1;i<=n;i++)
            {
                if(a[i]>ans)
                {
                    ans=a[i];
                }
            }
        }
        else
        {
            sort(a+1,a+n+1);
            for(int i=1;i<=m;i++)
            {
                ans=(ans&a[n-i+1]);
            }
        }
    }
    cout<<ans;
    return 0;
}
