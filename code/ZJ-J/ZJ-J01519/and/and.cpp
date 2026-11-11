#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, m;
int a[N], b[N];

bool check1()
{
	int ans = 0;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= 30; j ++)
		{
			if(a[i] + 1 == pow(2, j))
				ans ++;
		}
	return (ans == n);
} 

bool check2()
{
	for(int i = 1; i <= 30; i ++)
		if(n != pow(2, i))
			return false;
	for(int i = 1; i <= n; i ++)
		if(a[i] != i - 1)
			return false;
	return true;
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i]; 
	sort(a + 1, a + n + 1);
	if(check1() || check2())
	{
		int ans = a[n];
		for(int i = 1; i < m; i ++) ans = ans & a[n - i];
		cout << ans << endl;
		return 0;
	}
	
	return 0;
}
