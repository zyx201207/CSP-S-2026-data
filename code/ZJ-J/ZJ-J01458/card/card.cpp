#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10, M = 3e5 + 10;
int n, m;
int a[N];
int l[M];
set<int> s;
int cnt[M];
signed main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	int q[N], h = 0, t = 1;
	for(int i = n; i >= 1; i --)
	{
		if(s.count(a[i]))
		{
			while(h >= t && q[h] != a[i] && h != l[a[i]]) h --;
			if(h >= t) h --;
		}
		q[++ h] = a[i];
		l[a[i]] = h;
		s.insert(a[i]);
		for(int j = t; j <= h; j ++) cnt[q[j]] ++;
	}
	for(int i = 1; i <= m; i ++) cout << cnt[i] <<" ";
	return 0;
} 
