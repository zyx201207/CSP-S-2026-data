#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int m;
int f(const vector<int>& a)
{
	
	if (a.empty()) return 0;
	
	int ton[35]; memset(ton, 0, sizeof ton);
	vector<int> tmp[35];
	for (int i = 0; i < 35; i += 1) tmp[i].clear();
	
	for (auto num: a)
	{
		int p = num;
		for (int i = 0; i <= 32; i += 1)
		{
			if (num == 0) break;
			if (num & 1)
			{
				ton[i] += 1;
				tmp[i].push_back(p - ((p >> i) << i));
			}
			num >>= 1;
		}
	}
	
	for (int i = 32; i >= 0; i -= 1)
	{
		if (ton[i] >= m)
		{
			return (1 << i) + f(tmp[i]);
		}
	}
	return 0;
}
signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	
	int n;
	cin >> n >> m;
	vector<int> a; a.clear();
	for (int i = 1; i <= n; i += 1)
	{
		int x; cin >> x;
		a.push_back(x);
	}
	cout << f(a) << endl;
	return 0;
}
