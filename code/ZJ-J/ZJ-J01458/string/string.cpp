#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n;
string s;
long long ans;
struct l
{
	int x;
	char c;
	bool f;
}a[N];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i].x >> a[i].c;
		a[i].f = false;
	}
	int i = 1, j = n;
	for(; i < j; i ++)
		for(; j > i; j --)
		{
			if(a[j].f) continue;
			while(a[i].x > 0 || a[j].x > 0)
			{
				if(a[i].c != a[j].c) ans += min(a[i].x, a[j].x);
				int t = min(a[i].x, a[j].x);
				a[i].x -= t, a[j].x -= t;
				if(a[i].x > 0 && a[j].x == 0) j --, a[j].f = true;
				else if(a[j].x > 0 && a[i].x == 0) i ++, a[i].f = true;
			}
		}
	cout << ans << endl;
	return 0;
}
