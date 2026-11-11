#include <bits/stdc++.h>
using namespace std;
long long int n, m;
const int N = 2e5 + 5;
long long int a[N], b[N], cnt;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(cnt < a[i]) cnt = a[i];
	}	
	cout << cnt;
}
