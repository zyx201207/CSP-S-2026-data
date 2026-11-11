#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;

int n;
long long m;
long long a[N];

int find(int w, long long v)//suan
{
	int op = 1;
	if((a[w] - a[w - 1]) > v)
		return 1;
	for(int i = w - 1; i >= 1; i--)
	{
		v -= (a[w] - a[i]);
		if(v >= 0)
			op++;
		else
			return op;
	}
	return op;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);//xiao dao da
	int xx = 0;
	for(int i = n; i >= 1; i--)
	{
		if(i < n && a[i] == a[i + 1])
			continue;
		
		xx = max(xx, find(i, m));
	}
	cout << xx << endl;
	return 0;
}
