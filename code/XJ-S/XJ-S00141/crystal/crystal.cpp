#include<cstdio>
#include<algorithm>
//#include<cmath>
using namespace std;
int n,ans=1;
long long int a[510000];
long long int m;
long long int abs1(long long int num3)
{
	if(num3>=0)
	{
		return num3;
	}
//	printf("%lld        bbbbbbbbbbbbbbbbbbbbbbbbbbbbb\n",num3);
	return -num3;
}
long long int check(int l,int r)
{
	int i;
	long long int sum=0;
	long long int cut=a[r];
	for(i=l;i<=r;i++)
	{
		sum+=abs1(cut-a[i]);
//		printf("%lld %lld\n\n\n",sum,a[i]);
	}
//	printf("%lld %lld\n????????????????????\n",sum,cut);
	if(sum>m)
	{
		return -1;
	}
	return sum;
}
int dfs(int x,int y)
{
	int x2,y2;
//	printf("%d %d\n\n",x,y);
	x2=x+1;
	y2=y;
	if(x2>=y2 && x2>0 && y2>0 && x2<=n && y2<=n && check(y2,x2)!=-1)
	{
		ans=max(ans,x2-y2+1);
		dfs(x2,y2);
	}
	x2=x;
	y2=y-1;
	if(x2>=y2 && x2>0 && y2>0 && x2<=n && y2<=n && check(y2,x2)!=-1)
	{
		ans=max(ans,x2-y2+1);
		dfs(x2,y2);
	}
	x2=x-1;
	y2=y-1;
	if(x2>=y2 && x2>0 && y2>0 && x2<=n && y2<=n && check(y2,x2)!=-1)
	{
		ans=max(ans,x2-y2+1);
		dfs(x2,y2);
	}
	return 0;
}
int main()
{
	int i,j;
	FILE *in = fopen("crystal.in","r");
	FILE *out = fopen("crystal.out","w");
	fscanf(in,"%d %lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		fscanf(in,"%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	dfs(n,n);
	printf("%d",ans);
	return 0;
// continue
}
