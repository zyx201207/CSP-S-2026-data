#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int testc,T;
ll a[2000010];
void solve()
{
    int n;ll d;
    cin>>n>>d;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int l=1;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        while(l<=n && a[i]>a[l]+d)
        {
            l++;
        }
        ans+=(l-1);
    }
    if(a[n]-a[1]==2*d) ans--;
    cout<<ans<<"\n";
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>testc>>T;
    while(T--) solve();
    return 0;
}
/*
5:10 give up
*/
