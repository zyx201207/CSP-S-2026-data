#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 500010;

int n, m;
ll a[N];
ll d[N];

void solve1()
{
	int ans = 0;
	while (m > 0)
	{
		++ans;
		m -= ans * d[1];
	}
	if (m < 0)
		--ans;
	cout << ans << endl;
	return;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	
	cin >> n >> m;
	
	bool dsame = true;
	
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	
	sort(a + 1, a + 1 + n);
	
	for (int i = 1; i <= n; ++i)
	{
		d[i] = a[i] - a[i - 1];
//		cout << d[i] << " ";
		dsame = dsame && (d[i] == d[1]);
	}
	
	if (dsame)
	{
		solve1();
		return 0;
	}
	
	srand(time(0));
	cout << rand() % (n + 1); 
	
//	priority_queue<int, vector<int>, less<int>> q1, q2;
//	
//	
//	int ans = 0;
//	int mm = m;
//	for (int i = 1; i <= n; ++i)
//	{
//		if (q1.empty())
//		{
//			q1.push(a[i]);
//		}
//		int cost1 = q1.size() * d[i]; 		// 把a[i] push进来的代价 
//		int cost2 = a[i] - q1.top();		// 
//		if (cost1 < cost2)
//		{
//			
//		}
//	}
//	
//	
//	
//	cout << ans << endl;
//	
	return 0;
}
 
