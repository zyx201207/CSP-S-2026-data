#include <iostream>

using namespace std;

const int N = 5010;

int c, t, n, d;
int min_steps, min_cnt;
int x[N], dist[N];

void count_shortest_pathes(int st, int ed, int curr, int len)
{
	if (len > min_steps)
		return;
	if (curr == ed)
	{
		if (len < min_steps)
		{
			min_steps = len;
			min_cnt = 0; 
		}
		min_cnt++;
		return;
	}
	for (int i = curr + 1; x[i] - x[curr] <= d && i <= ed; ++i)
	{
//		cout << i << ' ';
		count_shortest_pathes(st, ed, i, len + 1);
	}
} 

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> d;
		for (int i = 1; i <= n; ++i)
		{
			cin >> x[i];
			dist[i - 1] = x[i] - x[i - 1];
//			cout << dist[i - 1] << ' ';
		}
//		cout << "\n";
		int ans = 0;
		for (int l = 1; l <= n; ++l)
		{
			for (int r = l + 3; r <= n; ++r)
			{
				min_steps = 0x3f3f3f3f;
				min_cnt = 0;
//				cout << "FROM " << l << " TO " << r << "\n";
				count_shortest_pathes(l, r, l, 0);
//				cout <<"RESULT " << min_cnt<<"\n" ;
				if (min_cnt == 2)
					ans++;
			}
		}
		cout << ans << "\n";
	}
	
	return 0;
}
 
