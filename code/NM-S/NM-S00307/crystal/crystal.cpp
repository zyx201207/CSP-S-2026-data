#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,ans,o[N],cnt;
long long m,a[N],s[N];
bool check(int k,int t)
{
	return k*a[t]-s[k]<=m;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=n;i>=1;i--)
	{
		s[i]=s[i+1]+a[i];
	}
	for (int i=1;i<=n;i++)
	{
		if (a[i]!=a[i-1])
		{
			o[cnt]=i-1;
			cnt++;
		}
	}
	cnt=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]==a[i-1])
		{
			continue;
		}
		cnt++;
		int l=1,r=o[cnt],res=-1;
		while (l<=r)
		{
			int mid=l+(r-l)/2;
			if (check(mid,i))
			{
				l=mid+1;
				res=mid;
			}
			else
			{
				r=mid-1;
			}
		}
		ans=max(ans,res);
	}
	cout<<ans;
	return 0;
}
