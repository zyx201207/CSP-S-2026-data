#include<bits/stdc++.h>
using namespace std;
#define int long long
int read()
{
	int ret = 0,f = 1;
	char g = getchar();
	while(!isdigit(g))
	{
		if(g=='-') f = -1;
		g = getchar();
	}
	while(isdigit(g))
	{
		ret = ret * 10 + g - '0';
		g = getchar();
	}
	return ret * f;
}
const int maxn = 2e6 + 7;
int C,T;
int n,d,x[maxn],nxt[maxn],bfe[maxn],ans;
bool f1[maxn],f2[maxn];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	C = read();T = read();
	while(T--)
	{
		ans = 0;
		n = read();d = read();
		for(int i = 1;i<=n;i++)
		{
			x[i] = read();
		}
		for(int i = 1;i<n;i++)
		{
			nxt[i] = upper_bound(x+1,x+n+1,x[i]+d) - x - 1;
		}
		nxt[n] = n;
		for(int i = 1;i<=n;i++)
		{
			bfe[i] = lower_bound(x+1,x+i+1,x[i]-d) - x;
		}
		for(int i = 1;i<n;i++)
		{
			for(int j = i+1;j<=n;j++)
			{
				int cc = 0;
				for(int k = i;k<=j;k++)
				{
					f1[k] = 0;f2[k] = 0;
				}
				int p = i;
				while(p<j)
				{
					f1[p] = 1;
					if(p == nxt[p])
					{
						cc = 3;
						break;
					}
					p = nxt[p];
				}
				p = j;
				while(p>i)
				{
					f2[p] = 1;
					if(p == bfe[p])
					{
						cc = 3;
						break;
					}
					p = bfe[p];
				}
				int t1=0,t2=0;
				for(int k = i+1;k<j;k++)
				{
					if(f1[k]==1&f2[k]==0)
					{
						t2 = k;
						cc++;
					}
					if(f1[k]==0&f2[k]==1)
					{
						t1 = k;
						cc++;
					}
				}
				if(t1&&t2&&cc==2&&t2-t1==1) ans ++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
