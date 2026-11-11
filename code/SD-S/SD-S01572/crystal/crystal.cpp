#include <bits/stdc++.h>
using namespace std;
# define int long long
const int N=5e5+10;
int n,m,a[N],maxx,sum;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
	{
		if(a[i]<=m)
		{
			n=i;
			break;
		}
	}
	int r=n;
	for(int i=n;i>=1;i--)
	{
		m=m-(a[r]-a[i]);
		sum++;
		while(m<0)
		{
			sum--;
			m+=(a[r]-a[r-1])*sum;
			r--;
		}
		maxx=max(sum,maxx);
	}
	cout<<maxx;
	return 0;
}
