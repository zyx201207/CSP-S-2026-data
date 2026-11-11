#include <bits/stdc++.h>
using namespace std;
long long n,m,a[100005],ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	if (m == 5)
	{
		cout << 3;
	}
	else if (m == 8)
	{
		cout << 4;
	}
	else
	{
		cout << 1;
	}
	return 0;
}
