#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N],cur = 0;
char c[N];
struct node
{
	long long wh;
	char ch;
	bool f;
}x[N];
bool cmp(node y,node z)
{
	return y.wh < z.wh;
}
char lc[2] = {' ',' '};
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	long long sum = 0;
	cin >> n;
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
		cin >> c[i];
		sum += a[i];
	}
	long long now = 1;
	for(int i = 1;i <= n;i ++)
	{
		x[++ cur] = {now,c[i],0};
		now += a[i];
		if(now > sum / 2)
		{
			break;
		}
	}
	now = 1;
	for(int i = n;i >= 1;i --)
	{
		x[++ cur] = {now,c[i],1};
		now += a[i];
		if(now > sum / 2)
		{
			break;
		}
	}
	sort(x + 1,x + cur + 1,cmp);
	long long last = 1;
	bool dif = 0;
	long long ans = 0;
	
	for(int i = 1;i <= cur;i ++)
	{
//		cout << x[i].wh << ' ' << last << ' ' << dif << '\n';
		ans += 1ll * (x[i].wh - last) * dif;
		lc[x[i].f] = x[i].ch;
		dif = (lc[0] != lc[1]);
		last = x[i].wh;
	}
	ans += 1ll * (sum / 2 - last + 1ll) * dif;
	cout << ans << '\n';
	return 0;
}
