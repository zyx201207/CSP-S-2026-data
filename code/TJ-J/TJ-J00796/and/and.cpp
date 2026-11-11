#include <bits/stdc++.h>
using namespace std;
long long a[100000];
long long n,m,maxn=-1111111;
long long yv(long long xl,long long yl)
{
	long long xll[100000],yll[100000];
	int i=0;
	while(xl>0 || yl>0)
	{
		i++;
		xll[i]=xl%2;
		xl/=2;
		yll[i]=yl%2;
		yl/=2;
	}
	long long ans=1;
	long long sum=0;
	for(int j=i;j>=1;j--)
	{
		ans=1;
		if(xll[i]==1 && yll[i]==1) sum+=ans;
		ans*=2; 
	}
	return sum;
}
void dfs(long long pos,long long sum,long long ans)
{
	if(pos==n) return;
	if(ans==m) 
	{
		maxn=max(maxn,sum);	
		return;
	}
	dfs(pos+1,yv(sum,a[pos]),ans+1);
	dfs(pos,sum,ans);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1,a[1],1);
	cout<<yv(3,15);
	return 0;
}

