#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+10;
int n;
ll m;
ll a[N];
bool check(int mid)
{
    ll ups = a[mid],cur = 0;
    for(int i = 1;i<=mid;i++)cur+=a[mid]-a[i];
    if(cur<=m)return 1;
    for(int i = mid+1;i<=n;i++)
    {
        cur-=a[i-1]-a[i-mid];
        cur+=1ll*(mid-1ll)*(a[i]-a[i-1]);
        if(cur<=m)return 1;
    }
    return 0;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i = 1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    int l = 1,r = n,ans = 1;
    while(l<=r)
    {
        int mid = (l+r)>>1;
        if(check(mid))l = mid + 1,ans = mid;
        else r=  mid - 1;
    }
    cout<<ans<<"\n";
    return 0;
}