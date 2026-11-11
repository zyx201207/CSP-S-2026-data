#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,tp=-1;
long long m,a[N],c[N],x,ans,anst;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort (a+1,a+n+1);
	for (int i=1;i<n;i++)
	{
		c[i]=a[i+1]-a[i];
		if (i!=1)
		{
			if (c[i]!=c[i-1])
			{
				tp=0;
			}
		}
	}
	if (tp==-1)
	{
		int i=0;
		while (m>=0)
		{
			i+=c[1];
			m-=i;
			ans++;
			if (ans==n)
			{
				cout << ans;
				return 0;
			}
		}
		cout << ans;
		return 0;
	}
	for (long long i=1;i<n;i++)
	{
		if ((n-i)<ans)
		{
			break;
		}
		x=0;
		anst=1;
		for (long long j=i+1;j<=n;j++)
		{
			x+=c[j-i]*(j-i);
			anst++;
			if (x>m)
			{
				anst--;
				break;
			}
		}
		ans=max(ans,anst);
	}
	cout << ans;
	return 0;
}