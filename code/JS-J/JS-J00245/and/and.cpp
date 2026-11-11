#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],s=0,ans=0;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(m==1)
    {
        for(int i=1;i<=n;i++)
            ans=max(ans,a[i]);
    }
    else if(m==n)
    {
        ans=a[1];
        for(int i=2;i<=n;i++)
        {
            ans&=a[i];
        }
    }
    else if(m==2)
    {
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
            {
                s=a[i];
                s&=a[j];
                ans=max(ans,s);
            }
    }
    cout<<ans;
}
