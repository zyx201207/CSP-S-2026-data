#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	long long n,m,a[50005];
	cin >> n >> m;
	for(long long i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(long long i = 1;i <= m;i++)
	{
		cout << i;
	}
	return 0;
}
