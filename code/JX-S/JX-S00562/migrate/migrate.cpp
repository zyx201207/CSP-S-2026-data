#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int x[N];
void solve()
{
    int n,l=1,d,ans=0,s=0;
    cin>>n>>d;
    cin>>x[1];
    for(int i=2;i<=n;i++)
    {
        cin>>x[i];
        if(x[i]-x[i-2]>d&&x[i-1]-x[i-2]<=d) s++;
        else s=0;
        if(l<i-3) l++;
        if(x[i]-x[i-1]>d) l=i;
        // cout<<i<<" "<<l<<endl;
        if(x[i]-x[l]>d&&x[i]-x[i-1]<d)
        {
            if(i-l==3)
            {
                ans+=(s+1),l++;
            }
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}