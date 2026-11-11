#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
const int M = 300005;
int a[N];
int ans[M];
int n, m;
int qu[114514];
int ed;
map<int, int> mp; 
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	for(int i = 1; i <= n; i ++)
	{
		ed = 0;
		mp.clear();
		//for(int i = 1; i <= n; i ++) qu[i] = 0;
		for(int j = i; j <= n; j ++) 
		{
			if(mp.find(a[j]) != mp.end() && mp[a[j]] != -1) 
			{
				for(int k = mp[a[j]] + 1; k <= ed; k ++) mp[qu[k]] = -1;
				ed = mp[a[j]];
				continue;
			}
			else 
			{
				ed ++;
				qu[ed] = a[j];
				mp[a[j]] = ed;
			}
		} 
		//for(int i = 1; i <= ed; i ++) cout << qu[i] << " ";
		for(int i = 1; i <= ed; i ++) ans[qu[i]] ++;
		//cout << '\n';
	}
	for(int i = 1; i <= m; i ++) cout << ans[i] << " ";
	return 0;
} 

