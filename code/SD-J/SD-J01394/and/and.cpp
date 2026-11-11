#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
long long a[N], n, m, maxx1 = INT_MIN, maxx2 = INT_MIN, maxx3 = INT_MIN;

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] > maxx1)maxx1 = a[i];
		else if(a[i] > maxx2 && a[i] <= maxx1)maxx2 = a[i];
		else if(a[i] > maxx3 && a[i] <= maxx2)maxx3 = a[i];
	}
	cout << maxx3;
	return 0;
} 
