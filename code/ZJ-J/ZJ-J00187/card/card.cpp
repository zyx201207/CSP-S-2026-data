#include<bits/stdc++.h>
using namespace std;

int a[500005];
vector<int> ans;
vector<vector<int>> idx;
int n, m;

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	ans.resize(m + 5, 0);
	idx.resize(m + 5);
	for(int i = 1; i <= n; ++ i)
	{
		cin >> a[i];
		idx[a[i]].push_back(i);
	}
	for(int i = 1; i <= n; ++ i)
	{
		for(int j = i; j <= n; ++ j)
		{   
			bool flag = true;
			for(int k = 0; k < (int)idx[j].size(); ++ k)
			{
				if(idx[a[j]][k] > j)
				{
					j = idx[a[j]][k] - 1;
					flag = false;
					break;
				}
			}
			if(flag)
			{
				++ ans[a[j]];
			}
		}
	}
	for(int i = 1; i <= m; ++ i)
	{
		cout << ans[i] << ' ';
	}
	cout << endl;
	return 0;
}