#include<bits/stdc++.h>
using namespace std;
long long n,m,mm,a[500010],ans[500010],mx;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=n;i>1;i--)
    {
        mm=m;
        for(int j=i-1;j>=1;j--)
        {
            if(a[i]-a[j]<=mm)
            {
                ans[i]++;
                mm-=(a[i]-a[j]);
            }
        }
    }
    mx=0;
    for(int i=1;i<=n;i++)
    {
        mx=max(mx,ans[i]);
    }
    cout<<mx+1;
    return 0;
}
