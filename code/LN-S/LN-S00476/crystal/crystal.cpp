#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int f[500005];
int b;
int ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1]+a[i];
	}
	ans=n;
	for(int i=n;i>=1;i--){
		while(i==b && a[i]*(i-b+1)<=m)
		{
			ans--;
		}
	}
	cout<<ans;
	return 0;
}
