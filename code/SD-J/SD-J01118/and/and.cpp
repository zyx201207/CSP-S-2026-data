#include <bits/stdc++.h>
using namespace std;
long long a[200010];
long long sum[200010];
bool cmp(long long x,long long y)
{
	return x > y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	sum[1] = a[1];
	for (int i = 2;i <= n;i++)
	{
		sum[i] = (sum[i-1]&a[i]);
	}
	cout << sum[m];
	cerr << sum[m];
	return 0;
}
