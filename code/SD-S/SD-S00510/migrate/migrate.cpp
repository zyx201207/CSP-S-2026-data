#include<bits/stdc++.h>
using namespace std;
long long n,d,a[2000050],dp[2000050],b[2000050],cnt;
struct node
{
	int x,w;
};
queue<node> q;
int v[2000050];
void bfs(int l)
{
	for(int i = 1;i <= n;i++)
	{
		dp[i] = 0;
		v[i] = 0;
	}
	q.push({l,1});
	dp[l] = 1;
	v[l] = 1;
	while(!q.empty())
	{
		node f = q.front();
		q.pop();
		if(f.x == n)continue;
		for(int i = f.x + 1;i <= b[f.x];i++)
		{
			if(v[i] == 0)q.push({i,f.w + 1});
			else if(v[i] < f.w)continue;
			v[i] = f.w;
			dp[i] += dp[f.x];
		}
	}
	return;
}
void init()
{
	//for(int i = 1;i <= n;i++)dp[i] = v[i] = b[i] = 0;
	cnt = 0;
	return;
}
void solve()
{
	init();
	cin >> n >> d;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if(n <= 3)
	{
		cout << 0 << "\n";
		return;	
	}
	for(int i = 1;i <= n;i++)
	{
		int id = upper_bound(a + 1,a + n + 1,a[i] + d) - a - 1;
		b[i] = id;
	}
	for(int i = 1;i <= n;i++)
	{
		bfs(i);
		for(int j = i;j <= n;j++)
		{
			if(dp[j] == 2)cnt++;
		}
	}
	cout << cnt << "\n";
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin >> c >> T;
	if(c == 11 || c == 12)
	{
		while(T--)
		{
			cin >> n >> d;
			for(int i = 1;i <= n;i++)
			{
				cin >> a[i];
			}
			if(n <= 3)
			{
				cout << 0 << "\n";
				break;
			}
			long long q = a[2] - a[1];
			long long p = d / q;
			if(p == 1)cout << 0 << "\n";
			else cout << n - (2 * p - 1) << "\n";
		}
	}
	else if(c == 13 || c == 14)
	{
		while(T--)
		{
			cnt = 0;
			cin >> n >> d;
			for(int i = 1;i <= n;i++)
			{
				cin >> a[i];
			}
			if(n <= 3)
			{
				cout << 0 << "\n";
				break;
			}
			for(int i = 1;i <= n;i++)
			{
				int id = upper_bound(a + 1,a + n + 1,a[i] + d) - a - 1;
				int id2 = upper_bound(a + 1,a + n + 1,a[id - 1] + d) - a - 1;
				int id3 = upper_bound(a + 1,a + n + 1,a[id - 2] + d) - a - 1;
				//cerr << id << " " << id2 << " " << id3 << "\n";
				if(id2 == id3 && id2 == n)break;
				cnt += id2 - id3;
			}
			cout << cnt << "\n";
		}
	}
	else while(T--)solve(); 
	return 0;
}
/*
Oct31==Dec25?

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6


*/
