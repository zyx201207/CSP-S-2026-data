#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

#define int long long

void solve()
{
	int n;
	long long d;
	scanf("%d%lld",&n,&d);
	vector<long long>x(n+1);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&x[i]);
	}
	vector<long long>f(n+1,0);
	vector<long long>L(n+1,0);
	vector<long long>R(n+1,0);
	vector<long long>sumf(n+1,0);
	long long l=1,r=0;
	L[1]=1;R[1]=0;
	for(int i=2;i<n;i++)
	{
		if(x[i]-x[i-1]>d)
		{
			f[i]=0;
			L[i]=i,R[i]=i;
		}
		else
		{
			while(x[i]-x[l]>d)
			{
				l++;
			}
			while(r+1<i&&x[i+1]-x[r+1]>d)
			{
				r++;
			}
			L[i]=l;
			R[i]=r;
			f[i]=sumf[r]-sumf[l-1]+(r-l+1);
		}
		sumf[i]=sumf[i-1]+f[i];
	}
	while(x[n]-x[l]>d)
	{
		l++;
	}
	L[n]=l,R[n]=n-1;
//	cout<<l<<endl;
	f[n]=sumf[n-1]-sumf[l-1]+(n-l);
	sumf[n]=sumf[n-1]+f[n];
	vector<long long>dp(n+1,0);
	vector<long long>sumdp(n+1,0);
	vector<long long>ans(n+1,0);
	long long sumans=0;
	for(int i=2;i<=n;i++)
	{
		if(x[i]-x[i-1]>d)
		{
			dp[i]=0;
		}
		else
		{
			if(L[i]<=R[i])
			{
				dp[i]+=sumdp[R[i]]-sumdp[L[i]-1];
				ans[i]+=sumdp[i-1]-sumdp[L[i]-1];
			}
			long long pr=R[L[i]+1],pl=L[L[i]+1];
//			if(L[i]<R[i])
			{
				if(L[i]+1<=R[i]&&pr>=pl)
				{
					dp[i]+=sumf[pr]-sumf[pl-1]+(pr-pl+1);
				}
				if(L[i]+1<i&&pr>=pl)
				{
//					cout<<i<<" "<<L[i]+1<<" "<<pl<<" "<<pr<<" "<<sumf[pr]-sumf[pl-1]+(pr-pl+1)<<endl;
					ans[i]+=sumf[pr]-sumf[pl-1]+(pr-pl+1);
				}
			}
		}
		sumans+=ans[i];
		sumdp[i]=sumdp[i-1]+dp[i];
	}
//	for(int i=2;i<=n;i++)
//	{
//		printf("%lld ",x[i]-x[i-1]);
//	}
//	puts("");
//	for(int i=1;i<=n;i++)
//	{
//		printf("%d ",L[i]);
//	}
//	puts("");
//	for(int i=1;i<=n;i++)
//	{
//		printf("%d ",R[i]);
//	}
//	puts("");
//	for(int i=1;i<=n;i++)
//	{
//		printf("%d ",f[i]);
//	}
//	puts("");
//	for(int i=1;i<=n;i++)
//	{
//		printf("%d ",dp[i]);
//	}
//	puts("");
//	for(int i=1;i<=n;i++)
//	{
//		printf("%d ",ans[i]);
//	}
//	puts("");
	printf("%lld\n",sumans);
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int Task,t;
	scanf("%d%d",&Task,&t);
	while(t--)
	{
		solve();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
10 2
1 2 3 4 5 6 7 8 9 10

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

0 1
7 3
0 2 4 5 6 7 9

*/