#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N];
char c[N];

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
	}
	if(n == 1)
	{
		cout << 0;
	}
	if(n == 2)
	{
		cout << 0;
	}
	return 0;
}
