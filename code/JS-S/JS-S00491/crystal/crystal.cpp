#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],m,ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(ans=n;ans>=1;ans--)
    {
        long long key=0,need=0;
        for(int i=n;i>=ans;i--)
        {
            for(int j=i-1;j>=i-ans+1;j--)
                need=need+(a[i]-a[j]);
            if(need<=m)
            {
                key=1;
                break;
            }
            need=0;
        }
        if(key==1)
            break;
    }
    cout<<ans<<endl;
    return 0;
}
