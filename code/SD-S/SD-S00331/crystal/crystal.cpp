#include<bits/stdc++.h>

using namespace std;
long long a[500005];
int chafen[500005];
int n;
long long m;
bool check(int id)
{
	long long sum=0;
	for(int i=(id-1);i>=1;i--)
	{
		sum+=(chafen[i]*i);
	}
	if(sum<=m) return 1;
	else return 0;
}
void solve2()
{
	for(int i=1;i<n;i++)
	{
		chafen[i]=(a[i+1]-a[i]);
	}
	int l=1,r=n;
	int ans=0;
	while(l<=r)
	{
		long long mid=(l+r)/2;
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
	cout << ans;
}
void solve1()
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int sum=0;
		int linshi=0;
		for(int j=i-1;j>=1;j--)
		{
			sum+=(a[i]-a[j]);
			if(sum>m)
			{
				ans=max(ans,(i-j));
				break;
			}
		}
		if(sum<=m) ans=max(ans,i);
	}
	cout << ans;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	if(n<=5000) solve1();
	else solve2();
	return 0;
}

