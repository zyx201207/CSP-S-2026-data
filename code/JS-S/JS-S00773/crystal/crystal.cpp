#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[500005],pref[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)pref[i]=pref[i-1]+a[i];
    int ans=0,l=1;
    for(int i=1;i<=n;i++)
    {
        while(a[i]*(i-l+1)-(pref[i]-pref[l-1])>m)l++;
        ans=max(ans,i-l+1);
    }
    cout<<ans<<endl;
    return 0;
}
