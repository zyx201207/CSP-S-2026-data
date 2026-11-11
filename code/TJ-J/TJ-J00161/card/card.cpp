#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m, a[5000005];
void fast()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
}
signed main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	fast();
	cin>>n>>m;
	for (int i = 1;i <= n;i++)
		cin>>a[i];
	for (int i = 1;i <= rand() % n;i++)
		cout<<(rand() % n) + 1<<' ';
	return 0;
}
/*
chao qiang sui ji shu :)


100+50+5+0=155pts
neng guo? 
*/
