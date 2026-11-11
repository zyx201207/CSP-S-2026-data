#include<bits/stdc++.h>
using namespace std;
long long n, m, ans, tcl, two[40], ch[200010], tmp[200010];
bool twice[200010][40];
void f(long long power)
{
	tcl = 0;
	if(power == -1)
	{
		return;
	}
	for(long long i = 1; i <= n; ++i)
	{	
		if(twice[i][power] == true)
		{
			tmp[++tcl] = ch[i];
//			if(ch[i] == 511 && power == 3)
//			{
//				cout << power << "Yes\n";
//			}
		}
	}
	if(tcl >= m)
	{
		for(long long i = 1; i <= tcl; ++i)
		{
			ch[i] = tmp[i];
		}
		n = tcl;
	}
//	if(power <= 3)
//	{
//		
//	
//	cout << tcl << "\n";
//	for(long long i = 1; i <= n; ++i)
//	{
//		cout << ch[i] << " ";
//	}
//	cout << "\n";
//}
	f(power - 1);
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(long long i = 1; i <= n; ++i)
	{
		cin >> ch[i];
	}
	two[0] = 1;
	for(long long i = 1; i <= 40; ++i)
	{
		two[i] = two[i - 1] * 2;
	}
	for(long long i = 1; i <= n; ++i)
	{
		long long tmpn = ch[i];
		for(long long j = 30; j >= 0; --j)
		{
			if(tmpn >= two[j])
			{
				twice[i][j] = true;
				tmpn -= two[j];
			}
			else
			{
				twice[i][j] = false;
			}
		}
	}
//	for(long long i = 1; i <= n; ++i)
//	{
//		for(long long j = 30; j >= 0; --j)
//		{
//			cout << twice[i][j];
//		}
//		cout << "\n";
//	}
	f(30);
	ans = ch[1];
	for(long long i = 2; i <= n; ++i)
	{
		ans = ans & ch[i];
	}
	cout << ans;
	return 0;
}
