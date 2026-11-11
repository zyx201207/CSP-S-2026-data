#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 500005;
ll a[N], s[N], m;

bool check(int mm, int i)
{
	if(s[i] - s[mm - 1] + m >= (i - mm + 1) * a[i]) return 1;
	else return 0;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	cin >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) s[i] = a[i] + s[i - 1];
	int ans = 0;
	for(int i = 2; i <= n; i++)
	{
		int l = 1, r = i;
		while(l < r)
		{
			int mid = (l + r) / 2;
			if(check(mid, i)) r = mid;
			else l = mid + 1;
		}
		ans = max(ans, i - r + 1);
	}
	cout << ans;
 } 
