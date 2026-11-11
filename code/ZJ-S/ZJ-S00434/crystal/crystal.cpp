#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,m;
ll a[N];
bool check(int x)
{
	int cnt=0,sum=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]<=x)
			sum+=x-a[i],cnt++;
		else if (sum>m)
			break;
		else if (a[i]>x)
			break;
	}
//	cout<<sum<<' '<<cnt<<endl;
	return sum<=m;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ll maxn=-inf;
	ll minn=inf;
	for (int i=1;i<=n;i++)
		cin>>a[i],maxn=max(maxn,a[i]),minn=min(minn,a[i]);
	sort(a+1,a+1+n);
	int l=minn,r=maxn;
	int ans=0;
//	for (int i=1;i<=n;i++)
//		cout<<a[i]<<' ';
//	cout<<endl;
	while (l+1<r)
	{
		int mid=(l+r)/2;
//		cout<<l<<' '<<r<<' '<<mid<<endl;
		if (check(mid))
			l=mid+1,ans=mid;
		else
			r=mid-1;
	}
	if (check(ans))
	{
		int cnt=0;
		int sum=0;
		for (int i=1;i<=n;i++)
		{
			if (a[i]<=ans)
				cnt++,sum+=ans-a[i];
			if (sum>m)
			{
				cout<<cnt;
				return 0;
			}
		}
		cout<<cnt;
	}
	else if (check(l))
	{
		int cnt=0;
		int sum=0;
		for (int i=1;i<=n;i++)
		{
			if (a[i]<=l)
				cnt++,sum+=ans-a[i];
			if (sum>m)
			{
				cout<<cnt;
				return 0;
			}
		}
		cout<<cnt;
	}
	else
	{
		int cnt=0;
		int sum=0;
		for (int i=1;i<=n;i++)
		{
			if (a[i]<=r)
				cnt++,sum+=ans-a[i];
			if (sum>m)
			{
				cout<<cnt;
				return 0;
			}
		}
		cout<<cnt;
	}
	return 0;
}
//Oct31==Dec25?
