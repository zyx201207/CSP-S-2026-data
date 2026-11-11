#include<bits/stdc++.h>
using namespace std;
set<long long> a;
long long jing[500005];
long long sum_cha[500005];
long long cha[500005];
long long sum[500005];
int maxn=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&jing[i]);
		//a.insert(jin);
	}
	sort(jing+1,jing+n+1);
	sum_cha[0]=0,sum[0]=0;
	cha[1]=0;
	for(int i=2;i<=n;i++)
	{
		cha[i]=jing[i]-jing[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+cha[i];
	}
	for(int i=1;i<=n;i++)
	{
		cha[i]*=(i-1);
	}
	for(int i=2;i<=n;i++)
		sum_cha[i]=sum_cha[i-1]+cha[i];
	for(int i=n;i>=1;i--)
	{
		int w=0;
		long long now_zhi=sum_cha[i];
		if(now_zhi<=m)
		{
			if(i>maxn) maxn=i;
			cout<<maxn;
			return 0;
		}
		else
		{
			while(now_zhi>m) 
			{
				w++;
				now_zhi=now_zhi-sum[i]+sum[w]; 
			}
			if(i-w>maxn) maxn=i-w;
		}
	}
	cout<<maxn;
	printf("%d",maxn);
	return 0;
} 
