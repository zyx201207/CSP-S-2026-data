#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500010],cnt=0,ans=0,f=1,z;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i>1)
        {
            if(i==2)
            {
                z=a[i]-a[i-1];
                continue;
            }
            else
            {
                if(z!=a[i]-a[i-1])
                {
                    f=0;
                }
            }
        }
    }
    if(f)
    {
        ans=1;
        while(ans*(ans-1)*z/2<=m)
        {
            ans++;
        }
        cout<<ans-1;
        return 0;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        cnt=1;
        int c=m;
        for(int j=i-1;j>=1;j--)
        {
            if(c>=a[i]-a[j])
            {
                cnt++;
                c-=(a[i]-a[j]);
            }
            else
            {
                break;
            }
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}
