#include<bits/stdc++.h>
using namespace std;
int n,a[2000005],m;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(m==1)
    {
        int maxn=-145;
        for(int i=1;i<=n;i++)
            maxn=max(maxn,a[i]);
        cout<<maxn;
        return 0;
    }
    if(m==n)
    {
        int ans=a[1];
        for(int i=1;i<=n;i++)
            ans=ans&a[i];
        cout<<ans;
        return 0;
    }
    if(m==2)
    {
        int ans=a[1]&a[2];
        for(int i=2;i<=n;i++)
            for(int j=1;j<i;j++)
                ans=max(ans,a[i]&a[j]);
        cout<<ans;
        return 0;
    }
}
