//杨云帆 陕西省西安中学 SN-S00325 
#include<bits/stdc++.h>
using namespace std;

int n = 0;//n <= 5 * 1e5
long long m = 0;
vector<long long> a;
vector<long long> s;

bool chick(int p)
{
	long long d = p * a[p];
	if (d <= m + s[p]) return true;
	else return false;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	a.resize(n + 1);
	s.resize(n + 1);
	for (int i = 1; i <= n; i ++)cin >> a[i];
	sort(a.begin(), a.end());
	for (int i = 1; i <= n; i ++) s[i] = s[i-1] + a[i];
	
	int l = 1, r = n;//下标 
	while (l < r)//找最大可行值 
	{
		int mid = (l + r + 1) / 2;
		if (chick(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << '\n';
	return 0;
}
