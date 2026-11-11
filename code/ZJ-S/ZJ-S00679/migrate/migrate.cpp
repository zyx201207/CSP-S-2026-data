#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> PII;
const int RP = 0x3f3f3f3f;
int n, d;
const int N = 2e6 + 10;
int x[N];
PII dc[N], dd[N];
int cnt, cnt2, ans;
int s1[N], s2[N];
int c, t;

void debug()
{
	for(int i = 1; i <= cnt; i ++) cerr << dc[i].first << ' ' << dc[i].second << '\n';
	for(int i = 1; i <= n; i ++) cerr << s1[i] << ' ';
	cerr << '\n';
	for(int i = 1; i <= n; i ++) cerr << s2[i] << ' ';
	cerr << "\n\n";
}
signed main()
{
freopen("migrate.in", "r", stdin);
freopen("migrate.out", "w", stdout);
ios::sync_with_stdio(false);
cin.tie(0);
	cin >> c >> t;
	while(t --)
	{
		ans = cnt = cnt2 = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; i ++) cin >> x[i];
		for(int i = 1, j = 2; j <= n; j ++)
		{
			while(x[j] - x[i] > d && i < j - 1) i ++;
			if(i != dc[cnt].first && x[j] - x[i] <= d && (j == n || x[j + 1] - x[i] > d))
				dc[++ cnt] = {i, j};
		}
		for(int i = 1; i < cnt; i ++)
			if(dc[i].second > dc[i + 1].first)
				dd[++ cnt2] = {dc[i].first, dc[i + 1].second};
		for(int i = 1, j = 1; j <= n; j ++)
			if(j == dd[i].second) s1[j] = s1[j - 1] + 1, i ++;
			else s1[j] = s1[j - 1];
		for(int i = 1, j = 0; j < n; j ++)
			if(j == dd[i].first) s2[j + 1] = s2[j] + 1, i ++;
			else s2[j + 1] = s2[j];
		debug();
		for(int i = 1, j = 1; i <= n && j <= n;)
		{
//			cerr << i << ' ' << j << '\n';
			if(x[j] - x[j - 1] > d) i = j, j ++;
			else if(s1[j] - s2[i - 1] == 1) ans ++, j ++;
			else if(s1[j] - s2[i - 1] > 1) i ++;
			else if(s1[j] - s2[i - 1] < 1) j ++;
		}
		cout << ans << '\n';
	}
	
	return 0;
}
