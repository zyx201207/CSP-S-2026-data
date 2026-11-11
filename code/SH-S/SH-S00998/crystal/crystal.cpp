#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500005;
int n;
ll m;
ll a[N],s[N];
bool ok(int x)
{
    ll k,sum=1e18;
    for(int i=1;i+x-1<=n;i++)
    {
        k=a[i+x-1];
        sum=min(sum,x*k-(s[i+x-1]-s[i-1]));
    }
    return sum<=m;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    s[0]=0;
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    int l=1,r=n,mid;
    while(l<r)
    {
        mid=((l+r+1)>>1);
        if(ok(mid))l=mid;
        else r=mid-1;
    }
    cout<<l<<'\n';
	return 0;
}
