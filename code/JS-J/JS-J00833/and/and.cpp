#include <bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int n,m,a[N],maxn,ans;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if (m==1)
        ans=maxn;
    if (m==n)
    {
        ans=a[1];
        for (int i=2;i<=n;i++)
        {
            ans=ans&a[i];
        }
    }
    if (m==2)
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=i+1;j<=n;j++)
            {
                int x=a[i]&a[j];
                ans=max(ans,x);
            }
        }
    }
    if (m==3)
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=i+1;j<=n;j++)
            {
                for (int k=j+1;k<=n;k++)
                {
                    int x=a[i]&a[j]&a[k];
                    ans=max(ans,x);
                }
            }
        }
    }
    if (m==4)
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=i+1;j<=n;j++)
            {
                for (int k=j+1;k<=n;k++)
                {
                    for (int s=k+1;s<=n;s++)
                    {
                        int x=a[i]&a[j]&a[k]&a[s];
                        ans=max(ans,x);
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
