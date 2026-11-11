#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int MAXN = 5e5 + 5;
ll n, m;
ll a[MAXN]={};
ll cha[MAXN]={};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i ++)
		cha[i] = a[i] - a[i-1];
	int i=1, j=2;
	ll need = 0;
	int num = 1;
	while(i <= n && j <= n)
	{
		need += cha[j]*(j-i);
		while (need > m)
		{
			need -= a[j]-a[i];
			i ++;
		}
		num = max(j - i + 1, num);
//		cout << i << ' ' << j << ":";
//		cout << need << '\n';
		j ++;
	}
	cout << num;
	return 0;
}