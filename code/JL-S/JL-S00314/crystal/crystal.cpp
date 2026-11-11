#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500001],ans=1,x,ans_max;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=n;i>=1;i--)
    {
        x=m;
        ans_max=1;
        for(int l=i-1;l>=1;l--)
        {
            x-=abs(a[l]-a[i]);
            if(x>=0)
                ans_max++;
            if(x<0||l==1)
            {
                ans=max(ans,ans_max);
            }
        }
        if(ans==n)
        {
            cout<<ans;
            return 0;
        }
    }
    cout<<ans;
    return 0;
}
