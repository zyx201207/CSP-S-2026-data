#include<bits/stdc++.h>
using namespace std;
const long long nx=5e5+20;
long long n,m,a[nx],s[nx],l,r,ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(r=1;r<=n;r++)
    {
        s[r]=s[r-1]+a[r];
        while((r-l)*a[r]-(s[r]-s[l-1])>m)
        {
            l++;
        }
        ans=max(ans,r-l);
    }
    cout<<ans<<endl;
    return 0;
}
