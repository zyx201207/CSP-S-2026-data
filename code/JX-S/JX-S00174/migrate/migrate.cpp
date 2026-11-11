#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
ll c,t,n,d;
ll a[N];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>t;
    while (t--)
    {
        cin>>n>>d;
        for (int i=1;i<=n;i++) cin>>a[i];
        ll ans=0;
        for (int len=4;len<=n;len++)
        {
            for (int l=1;l+len-1<=n;l++)
            {
                ll r=l+len-1,cnt=0;
                if (a[r]-a[l]<=d) continue;
                for (int k=l+1;k<r;k++)
                {
                    if (a[k]-a[l]<=d && a[r]-a[k]<=d) cnt++;
                }
                if (cnt==2) ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
