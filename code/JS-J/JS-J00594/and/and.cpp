#include<bits/stdc++.h>
using namespace std;
long long n,ans,x,a[200005],k,m,hh;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ans=max(a[i],ans);
        if(a[i]%2!=0)hh=1;
    }
    if(m==1)
    {
        cout<<ans;
        return 0;
    }
    if(m==n)
    {
        ans=a[1];
        for(int i=2;i<=n;i++)ans&a[i];
        cout<<ans;
        return 0;
    }
    ans=0;
    if(m==2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)ans=max(ans,a[j]&a[i]);
        }
        cout<<ans;
        return 0;
    }
    if(hh==0)
    {
        sort(a+1,a+n+1);
        cout<<a[m];
    }
    if(m+1==n)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=2;j<=n;j++)
            {
                if(j==i&&j-1==i)continue;
            k=a[j]&a[j-1];
            }
            ans=max(k,ans);
            k=0;
        }
    }
    else cout<<0;
}
