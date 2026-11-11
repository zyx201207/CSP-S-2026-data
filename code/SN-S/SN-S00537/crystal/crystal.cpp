#include <bits/stdc++.h>
using namespace std;
struct W
{
	int s;
	int cha;
};
bool cmp(W x, W y)
{
	return x.cha < y.cha;
}
W a[500005];
int b[500005];
int main()
{
	freopen("crystal3.in", "r", stdin);
	freopen("crystal3.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i].s;
	}
	int cnt = 0, t = 0;
	while(t<n)
	{
		for(int i = 0; i < t; i++)
		{
			a[i].cha = a[t].s - a[i].s;
			//cout << a[i].cha << " ";
		}
		//cout << endl;
		sort(a,a+t,cmp);
		int sum = 0;
		for(int i = 0; i < t; i++)
		{
			sum += a[i].cha;
			//cout << sum << " " << a[i].cha << endl;
			if(sum <= m) b[t] = i;
			else break;
		}
		t++;
		//cout << endl;
	}
	sort(b,b+n-1);
	cout << b[n-1]+2;
	return 0;
}
