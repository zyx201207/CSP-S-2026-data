#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N], b[N];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = n;i >= n - m + 1;i--) b[i] = 1;
	int mx = -1;
	do
	{
		int s = INT_MAX;
		for(int i = 1;i <= n;i++)
		{
			if(b[i] == 1) s &= a[i];
		}
		mx = max(mx, s);
	}while(next_permutation(b + 1, b + n + 1));
	cout << mx << '\n';
	return 0;
}
