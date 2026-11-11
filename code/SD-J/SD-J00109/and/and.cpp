#include <bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m,v[N],a[N][N],dp[N][N],x[N],js;//,a[N][N]
void f(int xx)
{
	for(int i=1;i<=60;i++)
	{
		v[i]=0;
	}
	int js=0;
	while(xx)
	{
		if(xx%2!=0) v[js]=1;
		js++;
		xx/=2;
	}
	for(int i=1;i<=js;i++)
	{
		a[xx][i]=v[js-i+1];
	}
	return;
}
bool cmp(int xxx,int y)
{
	return xxx>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
	}
	sort(x+1,x+n+1,cmp);
	/*for(int i=1;i<=n;i++)
	{
		f(i);
	}
	dp[0][1]=x[1];
	for(int i=1;i<=n;i++)
	{
		dp[i][1]=x[i];
		for(int j=1;j<=m;j++)
		{
			if(n>m) dp[i][j]=max(dp[i][j],dp[i][j]&dp[i-1][j]);
		}
	}*/
	int ansa=x[1];
	for(int i=2;i<=m;i++)
	{
		ansa=ansa&x[i];
	}
	printf("%d",ansa);
	return 0;
}
