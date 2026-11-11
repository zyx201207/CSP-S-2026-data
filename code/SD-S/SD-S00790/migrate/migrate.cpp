#include<iostream>
#include<cstdio>
using namespace std;

const int MAXN = 2e6+55;
long long c, t, n, d;
long long x[MAXN];

void solveA()
{
	long long a = x[2] - x[1];
	long long tt = d / a;
	if(tt == 0 || tt == 1)
	{
		cout << "0\n";
		return;
	}
	cout << max(0ll, n - 2 * tt + 1) << "\n";
	return;
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		for(int i = 1;i <= n;i++) cin >> x[i];
		if(n <= 3)
		{
			cout << "0\n";
			continue;
		}
		if(c == 11 || c == 12) solveA();
	}
	return 0;
}

