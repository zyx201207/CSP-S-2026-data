#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
const int M = 3e5 + 10;

int ans[M];
int a[N];

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef DEBUG
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
#endif // DEBUG
#ifdef DEBUG
//	freopen("card4.in", "r", stdin);
#endif // DEBUG
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
	{
		vector<int> res;
		vector<bool> t(m + 1);
		for(int j = i; j <= n; j++)
		{
			if(t[a[j]])
			{
				int p = res.size() - 1;
				while(true)
				{
					t[res.back()] = false;
					if(res.back() == a[j])
					{
						res.pop_back();
						break;
					}
					res.pop_back();
					p--;
				}
			}
			res.push_back(a[j]);
			t[a[j]] = true;
		}
		for(int x : res)
			ans[x]++;
	}
	for(int i = 1; i <= m; i++)
		cout << ans[i] << ' ';
	cout << '\n';

	return 0;
}

