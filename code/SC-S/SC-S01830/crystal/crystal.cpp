#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m,a[500005],sum = 0;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= sqrt(m);i++)
	{
		sum += i;
		if(sum > m)
		{
			cout << i;
			break;
		}
	}
	return 0;
}
/*
8 10
1 2 3 4 5 6 7 8

*/