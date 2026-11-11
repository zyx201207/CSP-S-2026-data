#include<bits/stdc++.h>
using namespace std;
long long a[200010];
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
    if(m==1)
    {
        long long big=INT_MIN;
        for(int i=1;i<=n;i++)
        {
            big=max(a[i],big);
        }
        cout<<big;
    }
    else if(m==2)
    {
        long long big=INT_MIN;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                big=max(big,a[i]&a[j]);
            }
        }
        cout<<big;
    }
    else if(m==n)
    {
        long long ans;
        for(int i=1;i<=n;i++)
        {
            if(i==1) ans=a[i];
            else ans=ans&a[i];
        }
        cout<<ans;
    }
    else if(m==3)
    {
        long long big=INT_MIN;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int k=j+1;k<=n;k++)
                {
                    big=max(big,a[i]&a[j]&a[k]);
                }
            }
        }
        cout<<big;
    }
    else if(m==n-1)
    {
        long long big=INT_MIN,ans;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(j==i) continue;
                if(j==1&&i!=1||j==2&&i==1) ans=a[j];
                else ans=ans&a[j];
            }
            big=max(big,ans);
        }
        cout<<big;
    }
    return 0;
}
