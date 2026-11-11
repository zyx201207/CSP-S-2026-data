#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int n, m;
int a[N];
bool check()
{
	int d = a[2] - a[1];
	for(int i = 3; i <= n; i ++)
		if(a[i] != a[i - 1] + d)
			return false;
	return true;
}
int main()
{
	freopen("crystal.in", "r", stdin);
 	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	if(check())
	{
		int num = 1, d = a[2] - a[1];
		while(m >= num * d)
		{
			m -= num * d;
			num ++;
		}
		cout << num << endl;
		return 0;
	}
	sort(a + 1, a + n + 1);
	int mid = (n + 1) / 2;
	int ans = 0, b, id;
	for(int i = mid; i <= n; i ++)
	{
		b = m;
		int res = 0;
		for(int j = i - 1; j >= 1; j --)
		{
			if(b >= (a[i] - a[j]) && a[i] != a[j])
			{
				b -= (a[i] - a[j]);
				res ++;
			}
		}
		if(ans < res)
		{
			ans = res;
			id = i;
		}
	}
	int num = 0;
	for(int i = 1; i <= n; i ++)
		if(a[i] == a[id])
			num ++;
	cout << ans + num << endl; 
	return 0;
} 
