#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 500000;
const int MAXM = 300000;
int n, m;
int a[MAXN + 5];
int cnt[MAXM + 5];
deque<int> q;
pair<bool, int> Find(int l, int r, int k)
{
	for(int i = l; i <= r; i++)
		if(q[i] == k)
			return {true, i};
	return {false, -1};
}
signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	q.push_back(-1);
	for(int i = 1; i <= n; i++)
	{
		for(int j = i; j <= n; j++)
		{
			int k = a[j];
			pair<bool, int> Pii = Find(1, j, k);
			if(Pii.first == true)
			{
				int pos = Pii.second;
				int siz = q.size();
				pos++;
				for(int i = pos; i <= siz; i++)
					q.pop_back();
			}
			q.push_back(k);
		}
		while(q.size() != 1)
		{
			int t = q.back();
			q.pop_back();
			cnt[t]++;
		};
	}
	for(int i = 1; i <= m; i++)
		cout << cnt[i] << " ";
	return 0;
}

