//17:03不想看T1了，来做T3了 
//17:09T3不会写，回去看一会T1
#include<bits/stdc++.h>
#define DEBUG 
#define N 500005
using namespace std;
int n;
long long m,a[N],sum[N];
int main()
{
	#ifndef DEBUG
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	#endif
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int ans;
	for(int i = 1;i <= n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	ans=r;
	for(int i = 2;i <= n;i++)//枚举基准 
	{
		int l=1,r=i+1;
		while(l+1<r)
		{
			int mid=(l+r)/2;
			if(check(mid))
			{
				
			}
		}
	}
}
