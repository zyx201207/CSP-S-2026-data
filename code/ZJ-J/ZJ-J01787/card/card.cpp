#include<bits/stdc++.h>
using namespace std;
int read(int &x)
{
	int O = 0; char c; x = 0;
	for(c = getchar(); (c < '0' || c > '9'); c = getchar()) O |= c == '-';
	for(; ('0' <= c && c <= '9'); c = getchar()) x = (x << 3) + (x << 1) + (c ^ '0');
	x = (O? -x : x);
}
struct card
{
	int l, r;
} c[500002];
int n, m, a[500002];
long long s[300002];
vector<int> e[300002];
bool pos(int num, int k)
{
	int l = 0, r = e[num].size() - 1, ans = 0;
	while(l <= r)
	{
		int mid = l + r >> 1;
		if(e[num][mid] >= k)
		{
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	read(n); read(m);
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		e[a[i]].push_back(i);
	}
	for(int t = 1; t <= n; t++)
	{
		for(int i = t; i <= n; i++)
		{
			if(e[a[i]].size() > 1 + pos(a[i], t))
			{
				i = e[a[i]][e[a[i]].size() - 1];
			}
			s[a[i]]++;
		}
	}
	for(int i = 1; i <= m; i++) cout << (long long)s[i] << ' ';
	return 0;
}