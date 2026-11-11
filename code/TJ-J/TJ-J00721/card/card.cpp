#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> a;

map<int, int> mp;

signed main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	a.resize(n + 5);
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	/* 
	if(n <= 500 && m <= 200)
	{
		map<int, int> mpp;
		for(int i = 0; i < n; i++)
		{
			vector<int> tmp;
			for(int j = i; j < n; j++) tmp.push_back(a[j]);
			map<int, int> mp;
			int j = i;
			for(vector<int>::iterator it = tmp.begin(); j < n; it++, j++)
			{
				if(!(mp[*it])) mp[*it] = j + 1;
				else
				{
					vector<int>::iterator itt = tmp.begin();
					int k = 0;
					while((*itt) != (*it)) itt++, k++;
					for(k++; k < j; k++)
						mp[a[k]] = 0, itt = tmp.erase(itt);
				}
			}
			for(int j : tmp) mpp[j]++; 
		}
		for(int i = 1; i <= m; i++) cout << mpp[i] << ' ';
	}
	*/
	for(int i = 1; i <= n; i++) mp[a[i]] = i;
	for(int i = 1; i <= m; i++)
	{
		cout << mp[i];
		if(i != m) cout << ' ';
	}
	cout << '\n';
	return 0;
}
//rp++
