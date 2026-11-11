#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[500005], s[500005];
bool check(int x)
{
	bool flag = 0;
	for(int i = 1; i <= n - x + 1; i++)
	{
		int R = i + x - 1; // i ~ R
		int needm = (x - 1) * a[R] - (s[R - 1] - s[i - 1]); // x = 3, i = 1, R = 3, 2 * 4 - (1 + 2)
		if(needm <= m) 
		{
			flag = 1;
			break;
		}
	}
	return flag;
}
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	for(int i = 1; i <= n; i++) cin>>a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	int l = 0, r = n;
	while(l < r)
	{
		int mid = (l + r + 1) / 2;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	cout<<l<<endl;
	return 0;
}
