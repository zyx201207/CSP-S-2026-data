#include<bits/stdc++.h>
using namespace std;
const int N = 200010;
int a[N], b[N];
int main()
{
	freopen("and1.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, maxn = 0, t;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			t = a[i] & a[j];
			if(t > maxn)
			{
				maxn = t;
			}
		}
	}
	cout << maxn;
	return 0;
}
