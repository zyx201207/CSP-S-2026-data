#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

using lnt = long long;

const int MAXN = 2e5+10;

lnt a[MAXN],n,m;
vector<lnt> vec,tmp_vec;

lnt dfs(int k)
{
	if (k == -1) return 0;
	lnt tmp = 1 << k;
	for (int i:vec) if (i&tmp) tmp_vec.push_back(i);
	if (tmp_vec.size() >= m)
	{
		vec.clear();
		for (int i:tmp_vec) vec.push_back(i);
		tmp_vec.clear();
		return tmp + dfs(k-1);
	}
	else
	{
		tmp_vec.clear();
		return dfs(k-1);
	}
}

void Solve()
{
	cin >> n >> m;
	lnt x; for (int i=1;i<=n;i++) cin >> x, vec.push_back(x);
	sort(a+1,a+n+1,greater<int>());
	cout << dfs(30); 
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1; //cin >> T;
	while (T--) Solve();
	return 0;
}
