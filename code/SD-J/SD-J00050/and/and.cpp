#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 2e5 + 10;
const int inf = 1e18;
int n,m;
int a[N];
struct node
{
	string t;
	int id;
}p[N];
int cnt[100];
bool cmp(node x,node y)
{
	return x.t > y.t;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		string s = "";
		for(int j = 30; j >= 0; j--)
		{
			if((a[i] >> j) & 1) s += '1';
			else s += '0';
		}
		for(int j = 0; j < s.size(); j++)
			if(s[j] == '1') cnt[j]++;
		p[i].t = s;
		p[i].id = i;
	}
	for(int i = 1; i <= n; i++)
	{
		string s = p[i].t;
		for(int j = 0; j < s.size(); j++)
			if(cnt[j] < m) s[j] = '0';
		p[i].t = s;
	}
	sort(p + 1, p + n + 1, cmp);
	int ans = -inf;
	for(int i = 1; i <= m; i++)
	{
		if(ans == -inf) ans = a[p[i].id];
		else ans &= a[p[i].id];
	}
	cout << ans << endl;
	return 0;
}
