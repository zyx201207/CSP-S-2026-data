#include<bits/stdc++.h>
using namespace std;
long long a[200005],dp[200005],ans=0,b=1,x=-1;
int n,m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		ans=max(ans,a[i]);
		b=b&a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j =i+1;j <= n;j++)
		{
			x=max(x,a[i]&a[j]);
		}
	}
	if(m==1)cout << ans;
	if(m==n)cout << b;
	if(m==2)cout << x;
	return 0;
}
