#include<bits/stdc++.h>
using namespace std;
#define int long long
int s[1000001][40];
int a[1000001];
int q[1000001];
int b[1000001];
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=0;i<=30;i++)
	{
		q[i]=pow(2,i);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int x=a[i];
		for(int j=30;j>=0;j--)
		{
			if(x>=q[j])
			{
				s[i][j]=1;
				x-=q[j];
			}
		}
	}
	for(int i=30;i>=0;i--)
	{
		b[i]=s[1][i];
	}
	for(int i=2;i<=m;i++)
	{
		for(int j=30;j>=0;j--)
		{
			if(b[j]==1&&s[i][j]==1)
			{
				b[j]=1;
			}
			else b[j]=0;
		}
	}
	int ret=0;
	for(int i=30;i>=0;i--)
	{
		if(b[i])
		{
			ret+=pow(2,i);
		}
	}
	printf("%lld",ret);
	return 0;
}


