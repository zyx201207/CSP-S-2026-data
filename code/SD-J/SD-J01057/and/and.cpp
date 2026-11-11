#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int n, m;
int a[MAXN];
int ans;
int px(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a+1, a+1+n, px);
	if(m == 2 && n <= 10000)
	{
		for(int i = 1; i < n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				int sum = a[i] & a[j];;
				//cout << sum << ' ';
				ans = max(ans, sum);
			 } 
		}
		cout << ans;
		return 0;
	}
	ans = a[1];
	//cout << a[1] << ' ';
	for(int i = 2; i <= m; i++)
	{
		ans = ans & a[i];
		//cout << a[i] << ' ';
	}
	cout << ans;
	
	return 0;
}//Trick||Treat!
