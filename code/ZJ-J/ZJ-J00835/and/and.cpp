#include<bits/stdc++.h>
using namespace std;
bool bo=0,c[40][200010];
int n,m,b[40];
long long a[200010],MAX,sum;
void dfs(int k,int l,long long s)
{
	if(k>m)
	{
		MAX=max(MAX,s);
		return;
	}
	for(int i=l+1;i<=n;i++)dfs(k+1,i,(s&a[i]));
}
long long check(long long x)
{
	if(x==0)return 1;
	long long h=1;
	for(int i=1;i<=x;i++)h*=2;
	return h;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	if(m==1)
	{
		long long M=0;
		for(int i=1;i<=n;i++)M=max(M,a[i]);
		cout<<M<<'\n';
		return 0;
	}
	if(m==n)
	{	
		long long sum=a[1];
		for(int i=2;i<=n;i++)sum&=a[i];
		cout<<sum<<'\n';
		return 0;
	}
	if(m==2&&n<=2000)
	{
		long long ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,(a[i]&a[j]) );
			}
		cout<<ans<<'\n';
		return 0;
	}
	if(n<=20)
	{
		for(int i=1;i<=n;i++)dfs(2,i,a[i]);
		cout<<MAX<<'\n';
		return 0;
	}
	long long MIN=1e9;
	for(int i=1;i<=n;i++)MIN=min(MIN,a[i]);
	cout<<MIN<<'\n';
	return 0;
}
/*
4 3
3 15 12 12
*/
