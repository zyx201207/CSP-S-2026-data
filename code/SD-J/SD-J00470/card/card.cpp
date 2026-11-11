#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int MAXN = 5e5 + 5;
ll ans[MAXN];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	bool j1 = 1;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(i != 1 && a[i] < a[i - 1] && j1) j1 = 0;
	}
	if(j1)
	{
		for(int i = n; i >= 1; i--)
		{
			ans[a[i]] += 1;
		}
	}
}
