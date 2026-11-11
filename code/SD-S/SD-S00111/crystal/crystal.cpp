#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int P=998244353;
const long long INF=0x3f3f3f3f3f3f3f3f;
const int N=5e5+10,M=2e6+10;

int n;
long long m;
long long a[N],s[N];
long long ans;

bool check(int mid)
{
	for(int i=mid;i<=n;i++)
	{
		long long sum=a[i]*mid-(s[i]-s[i-mid]);
		if(sum<=m)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
