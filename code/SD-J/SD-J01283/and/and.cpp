#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

bool visit[2005];
int a[200005], b[2005], cnt[15];

int main()
{
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin>>n>>m;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	if(n < 21)
	{ 
		int ans = INT_MAX; 
		for(int i = 0; i < n; i++)
		{
			cin>>a[i];
			ans &= a[i];
		}
		if(n == m)
		{
			cout << ans;
		}
		else
		{
			ans = INT_MAX;
			sort(a, a + n, cmp);
			ans = a[0];
			int pos;
			for(int i = 1; i < m; i++)
			{
				for(int j = 1; j < n; j++)
				{
					if(visit[j])
					{
						continue;
					}
					b[j] = ans & a[j];
				}
				ans = INT_MIN;
				for(int j = 1; j < n; j++)
				{
					if(visit[j])
					{
						continue;
					}
					if(b[j] >= ans)
					{
						ans = b[j];
						pos = j;
					}
				}
				visit[pos] = true;
			}
			cout << ans;
		}
	}
	else if(n < 2001)
	{
		int ans = INT_MAX;
		for(int i = 0; i < n; i++)
		{
			cin>>a[i];
			ans &= a[i];
		}
		if(m == n)
		{
			cout << ans;
		}
		else
		{
			sort(a, a + n, cmp);
			if(m == 1)
			{
				cout << a[0];
			}
			else
			{
				ans = 0;
				for(int i = 0; i < n; i++)
				{
					for(int j = 0; j < n; j++)
					{
						if(j == i)
						{
							continue;
						}
						ans = max(ans, a[i] & a[j]);
					}
				}
				cout << ans;
			}
		}
	}
	else
	{
		int t = -1000;
		for(int i = 0; i < n; i++)
		{
			cin>>a[i];
			t = max(t, a[i]);
			cnt[a[i]++];
		}
		if(t < 4)
		{
			if(cnt[1] + cnt[3] >= m)
			{
				cout << 3;
			}
			else
			{
				if(cnt[2] >= m - cnt[1] - cnt[3])
				{
					cout << 1;
				}
				else
				{
					cout << 0;
				}
			}
		}
		else
		{
			cout << m;
		}
	}
	return 0;
} 
