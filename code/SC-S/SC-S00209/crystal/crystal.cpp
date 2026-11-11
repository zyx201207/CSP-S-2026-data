#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

const int N = 5e5 + 5;
ll a[N];

int main(void)
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	ll m;
	cin >> n >> m;
	bool f1 = true, f2 = true;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] != i)
		{
			f1 = false;
		}
		if(i > 2 && a[i] - a[i - 1] != a[i - 1] - a[i - 2])
		{
			f2 = false;
		}
	}
	if(f1 || f2)
	{
		int cnt = 1;
		for(ll i = 1;m >= i * (a[2] - a[1]);i++)
		{
			m -= i * (a[2] - a[1]);
			cnt++;
			if(cnt == n)
			{
				break;
			}
		}
		cout << cnt;
		return 0;
	}
} 