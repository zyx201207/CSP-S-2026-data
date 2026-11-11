#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int lr[2000010],rl[2000010],l[2000010],r[2000010],x[2000010];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--)
	{
		int n,d,ans = 0;
		cin >> n >> d;
		x[0] = -4e18;
		for(int i = 1;i <= n;i++) scanf(" %lld ",x + i);
		x[n + 1] = 4e18;
		lr[n + 1] = rl[n + 1] = n + 1;
		lr[0] = rl[0] = 0;
		for(int i = 1,p = 0;i <= n;i++)
		{
			while(x[p] + d < x[i]) p++;
			lr[i] = p;
		}
		for(int i = n,p = n + 1;i >= 1;i--)
		{
			while(x[p] > x[i] + d) p--;
			rl[i] = p;
		}
		for(int i = 2;i <= n;i++)
		{
			if(lr[i + 1] == lr[i]) l[i] = 0;
			else
			{
				l[i] = l[lr[i]];
				l[i] += min(lr[i + 1],i) - lr[i];
			}
		}
		for(int i = n - 1;i >= 1;i--)
		{
			if(rl[i - 1] == rl[i]) r[i] = 0;
			else
			{
				r[i] = r[rl[i]];
				r[i] += rl[i] - max(i,rl[i - 1]);
			}
		}
		for(int i = 1;i < n;i++)
			if(lr[i + 1] < i && rl[i] > i + 1)
			{
				int c1,c2;
				if(lr[i + 1] == lr[i]) c1 = l[i + 1] - (lr[i + 1] >= i);
				else c1 = min(lr[i + 2],i) - lr[i + 1];
				if(rl[i + 1] == rl[i]) c2 = r[i] - (rl[i - 1] <= i);
				else c2 = rl[i] - max(i + 1,rl[i - 1]);
				ans += c1 * c2;
			}
		cout << ans << endl;
		memset(l,0,sizeof(l));
		memset(r,0,sizeof(r));
		memset(lr,0,sizeof(lr));
		memset(rl,0,sizeof(rl));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
