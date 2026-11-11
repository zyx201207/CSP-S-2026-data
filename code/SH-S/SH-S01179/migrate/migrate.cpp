#include<bits/stdc++.h>
using namespace std;

long long x[2000010];
int l[2000010];
int r[2000010];
int cntl[2000010];
int cntr[2000010];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--)
	{
		long long n,d,ans = 0;
		cin >> n >> d;
		for(int i = 1;i <= n;i++)
			scanf("%lld",&x[i]);
		for(int i = 1,j = 1;i <= n;i++)
		{
			while(x[i] - x[j] > d)j++;
			l[i] = j;
		}
		for(int i = n,j = n;i >= 1;i--)
		{
			while(x[j] - x[i] > d)j--;
			r[i] = j;
		}
		for(int i = n;i >= 1;i--)
		{
			cntr[i] = r[i] - r[i - 1];
			if(l[r[i]] == i)cntr[i] += cntr[r[i]];
		}
		for(int i = 1;i <= n;i++)
		{
			cntl[i] = l[i + 1] - l[i];
			if(r[l[i]] == i)cntl[i] += cntl[l[i]];
		}
		for(int i = 2;i <= n - 2;i++)
		{
			if(r[i] == i + 1 || l[i + 1] == i)continue;
			ans += 1ll * cntl[i + 1] * cntr[i];
		}
		cout << ans << "\n";
	}
	return 0;
}
