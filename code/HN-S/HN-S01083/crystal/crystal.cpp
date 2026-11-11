#include<bits/stdc++.h>
using namespace std;
const int N=5e5+12;
typedef long long ll;
ll n,a[N],sum[N],m,ant[N];
struct node
{
	ll x,tot;
}b[N];
ll c[N];
void solve()
{
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)c[i]=a[i];
	int t=unique(c+1,c+1+n)-c-1;
	for(int i=1;i<=n;i++)
	{
		int t2=lower_bound(c+1,c+1+t,a[i])-c;
		b[t2].x=a[i],b[t2].tot++;
	}
	for(int i=1;i<=t;i++)sum[i]=sum[i-1]+b[i].x*b[i].tot,ant[i]=ant[i-1]+b[i].tot;
	ll da=0;
	for(int i=1;i<=t;i++)
	{
		ll l=1,r=i,ans=0;
		while(l<=r)
		{
			int mid=l+r>>1;
			if((ant[i-1]-ant[mid-1])*b[i].x-(sum[i-1]-sum[mid-1])<=m)
			{
				ans=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		ll b1=ant[i]-ant[ans-1],b2=m-(ant[i-1]-ant[ans-1])*b[i].x+(sum[i-1]-sum[ans-1]);
		if(ans>1)
		{
			ll t1=b[i].x-b[ans-1].x;
			b1+=b2/t1;
		}
		da=max(da,b1);
	}
	cout<<da<<'\n';
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    solve();
	return 0;
}
/*

hello!
14:30 start

5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

14:52 end
AC!

duipai£º11300 No wrong
*/
