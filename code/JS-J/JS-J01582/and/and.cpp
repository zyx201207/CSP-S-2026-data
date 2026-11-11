#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200007],ans=0,cnt;
bool cmp(ll x,ll y)
{
    return x>y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n-m+1;i++)
    {
        cnt=a[i];
        for(int j=i;j<=m+i-1;j++)
        {
            cnt&=a[j];
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}
