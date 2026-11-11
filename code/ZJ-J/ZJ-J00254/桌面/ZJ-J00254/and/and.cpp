#include <bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    if(n==m)
    {
        int ans=a[1];
        for(int i=2;i<=n;++i)
        {
            ans&=a[i];
        }
        cout<<ans;
        return 0;
    }
    else if(m==1)
    {
        int ans=0;
        for(int i=1;i<=n;++i)
        {
            ans=max(ans,a[i]);
        }
        cout<<ans;
        return 0;
    }
    else if(m==2)
    {
        int ans=0;
        for(int i=1;i<=n;++i)
        {
            for(int j=i+1;j<=n;++j)
            {
                int xz=a[i];
                xz&=a[j];
                ans=max(ans,xz);
            }
        }
        cout<<ans;
        return 0;
    }
    else 
    {
        sort(a.begin()+1,a.end(),greater<int>());
        int ans=a[1];
        for(int i=2;i<=m;++i)
        {
            ans&=a[i];
        }
        cout<<ans;
    }
    return 0;
}