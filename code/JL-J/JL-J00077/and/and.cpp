#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int a[N];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, k;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{ 
		cin>> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		a[i] = i - 1;
		k = a[i]& i;
	}
	cout << k;
	return 0;
}
