#include <bits/stdc++.h>
using namespace std;

int n,m;
long long a[200005];

long long maxx;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	maxx = a[n];
	for(int i = n;i > n-m;i--)
	{
		maxx = a[i] & maxx;
	}
	cout << maxx;
	return 0;
}
