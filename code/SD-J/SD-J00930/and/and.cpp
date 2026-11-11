#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
int n, m;
LL a[N];
int mxpos[N];
int b[32][N];
bool pas[N];
vector<int> pos;
LL ans;
LL getans(int p, int len)
{
	LL res = 0;
	for(int i = 0; i <= len; i ++) pas[i] = 0;
	for(int i = p - 1; i >= 0; i --)
	{
		int h = 0;
		for(int j = 0; j < len; j ++) 
		{
			if(pas[j]) continue;
			else h += b[i][j];
		}
		if(h >= m) 
		{
			res += (1 << i);
			for(int j = 0; j < len; j ++) if(!b[i][j]) pas[j] = 1;
		}
	}
	return res;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	if(m == 1) 
	{
		cout << a[1] << endl;
		return 0;
	}
	else if(m == n) 
	{
		ans = a[1];
		for(int i = 1; i <= n; i ++) ans &= a[i];
		cout << ans << endl;
		return 0;
	}
	for(int i = 1; i <= n; i ++) 
	{
		int k = a[i];
		for(int j = 0; j <= 31; j ++) 
		{
			if(k & (LL)(1 << j))
			{
				b[j][i] = 1;
				mxpos[i] = max(j, mxpos[i]);
			}
		}
	}
	for(int i = 30; i >= 0; i --) 
	{
		int has1 = 0;
		int len = 0;
		for(int j = 1; j <= n; j ++) 
		{
			has1 += b[i][j];
			pos.push_back(j);
			len ++;
		}
		if(has1 >= m) 
		{
			ans += (LL)(1 << i) + (LL)(getans(i, len));
			cout << ans << endl;
			return 0;
		}
		pos.clear();
	}	
	cout << 0 << endl;
	return 0;
}
