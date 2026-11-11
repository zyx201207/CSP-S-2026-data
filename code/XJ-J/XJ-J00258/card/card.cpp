#include<bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 7;
int n,m;
int a[N];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	cout << n;
	return 0;
}