#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[1000009] = {0};
int dp[5009][5009] = {0};
int kt[5009][5009] = {0};
int ft[1000009] = {0};
int pt[1000009] = {0};
int yu[1000009] = {0};
int cc,T;
int check1()
{
	for(int i = 3; i<=n; ++i)
	{
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]) return 0;
	}
	return 1;
}
int bl1()
{
	int t = m/(a[2]-a[1]);
	if(t==1||n-(2*t-1)<0)
	{
		printf("0\n");
		return 0;
	}
	printf("%lld\n", n-(2*t-1));
}
int check2()
{
	return cc==13||cc==14;
}
int yc()
{
	for(int i = 1; i<=n; ++i) ft[i]=i;
	for(int i = 1; i<=n; ++i)
	{
		if(a[i]-a[1]<=m) ft[1]++;
		else
		{
			ft[1]--;
			break;
		}
	}
	int ty = ft[1];
	for(int i = 2; i<=n; ++i)
	{
		while(a[ty]-a[i]<=m&&ty<=n) ty++;
		ft[i]=ty-1;
	}
	for(int i = n; i>=1; --i) pt[i]=i;
	for(int i = n; i>=1; --i)
	{
		if(a[n]-a[i]<=m) pt[n]--;
		else
		{
			pt[n]++;
			break;
		}
	}
	ty = pt[n];
	for(int i = n-1; i>=1; --i)
	{
		while(a[i]-a[ty]<=m&&ty>=1) ty--;
		pt[i]=ty+1;
	}
}
int bl2()
{
	yc();
	for(int i = 1; i<=n; ++i) yu[pt[i]]++;
	//for(int i = 1; i<=n; ++i) printf("%lld ", pt[i]);
	int ans = 0;
	for(int i = 1; i<=n; ++i)
	{
		if(ft[i]-i<=1) continue;
		ans+=yu[ft[i]-1];
	}
	printf("%lld\n", ans);
}
int bl3()
{
	yc();
	for(int i = 1; i<=n; ++i)
	{
		for(int j = i; j<=ft[i]; ++j)
		{
			dp[i][j]=1;
			dp[j][i]=1;
		}
	}
	for(int i = 1; i<=n; ++i)
	{
		for(int j = i; j<=n; ++j)
		{
			kt[i][j]=1;
		}
	}
	for(int i = 1; i<=n; ++i)
	{
		for(int j = i+1; j<=n; ++j)
		{
			for(int k = pt[j]; k<=j; ++k)
			{
				if(dp[i][j]>dp[i][k]+1)
				{
					dp[i][j]=dp[i][k]+1;
					kt[i][j]=kt[i][k]*kt[k][j];
				}
				else if(dp[i][j]==dp[i][k]+1)
				{
					kt[i][j]+=kt[i][k]*kt[k][j];
				}
			}
		}
	}
	int ans = 0;
	for(int i = 1; i<=n; ++i)
	{
		for(int j = i+1; j<=n; ++j)
		{
			ans+=(kt[i][j]==2);
		}
	}
	printf("%lld\n", ans);
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld", &cc, &T);
	for(int iii = 1; iii<=T; ++iii)
	{
		memset(dp,0x3f,sizeof(dp));
		memset(a,0,sizeof(a));
		memset(ft,0,sizeof(ft));
		memset(pt,0,sizeof(pt));
		memset(yu,0,sizeof(yu));
		memset(kt,0,sizeof(kt));
		scanf("%lld%lld", &n, &m);
		for(int i = 1; i<=n; ++i)
		{
			scanf("%lld", &a[i]);
		}
		if(check1())
		{
			bl1();
		}
		else if(check2())
		{
			bl2();
		}
		else
		{
			bl3();
		}
	}
	return 0;
}
/*
10 1
9 8
1 3 4 6 8 11 12 16 18
*/
