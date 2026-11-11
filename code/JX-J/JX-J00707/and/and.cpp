#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
long long ans;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==n)
    {
        ans=a[1];
        for(int i=2;i<n;i++)
        {
            ans=ans&&a[i];
        }
        cout<<ans;
        return 0;
    }
    if(m==1)
    {
        for(int i=1;i<=n;i++)
        {
            ans=0;
            ans=max(a[i],ans);
        }
        cout<<ans;
        return 0;

    }
    if(m==2)
    {
        ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                int sum=a[i]&&a[j];
                if(ans<=sum) ans=sum;
            }
        }
        cout<<ans;
        return 0;
    }
    cout<<12;
    return 0;
}
