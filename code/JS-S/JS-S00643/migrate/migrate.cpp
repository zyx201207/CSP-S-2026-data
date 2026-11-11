#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=2000005;
ll arr[maxn];
ll c,t,n;
ll d;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(ll i=1;i<=n;i++)cin>>arr[i];
        int j,ans=0;
        for(ll i=n;i>3;i--)
        {
            ll p=arr[i]-d;
            for(ll k=i-1;k>=1 && arr[k]>=p;k--)j=k;
            if(i-j<2)
            {
                continue;
            }
            ll l=arr[j+1]-d,r=arr[j+2]-d;
            for(ll k=j-1;k>=1 && arr[k]>=l && arr[k]<r;k--)
            {
                ans+=1;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
