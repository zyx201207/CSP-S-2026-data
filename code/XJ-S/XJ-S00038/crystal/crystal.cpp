#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
int n,a[MAXN],mid,midi,d[MAXN],b[MAXN],ans;
long long m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++)
	{
		d[i] = (i == 1) ? 0 : a[i]-a[i-1];
		d[i] += d[i-1];
	}
	for(int i = n;i>=1;i--)
	{
		if(m>=d[i])
		{cout << i;
		break;}
	}
	return 0;
}
