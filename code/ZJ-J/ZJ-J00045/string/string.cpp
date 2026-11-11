#include<bits/stdc++.h>
using namespace std;
#define int long long

struct node{
	int a;
	char c;
}a[200005];
int zs[200005],fs[200005];

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i].a >> a[i].c;
	}
	for(int i = 1;i <= n;i++)
	{
		zs[i] = zs[i - 1] + a[i].a;
	}
	for(int i = n;i >= 1;i--)
	{
		fs[i] = fs[i + 1] + a[i].a;
	}
	int ans = 0;
	int u = n;
	for(int i = 1;i <= n;i++)
	{
		while(fs[u] < zs[i - 1] + 1)
		{
			u--;
		}
		for(int j = u;j >= 1;j--)
		{
			int r = min(zs[i],fs[j]);
			int l = max(zs[i - 1] + 1,fs[j + 1] + 1);
			if(a[i].c != a[j].c)
			{
				ans += r - l + 1;
			}
			if(fs[j] > zs[i])
			{
				u = j;
				break;
			}
		}
	}
	cout << ans / 2;
	return 0;
}