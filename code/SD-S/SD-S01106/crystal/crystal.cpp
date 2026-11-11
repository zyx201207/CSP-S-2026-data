#include<stdio.h>
#include<algorithm>
long long a[500000];
long long t[500001];
int gn;
int lowbit(int x)
{
	return x&(-x);
}
void add(int x,long long a)
{
	x++;
	int i;
	for(i=x;i<=gn;i+=lowbit(i))
	{
		i[t]+=a;
	}
}
long long sum(int x)
{
	x++;
	int i;
	long long ans=0;
	for(i=x;i!=0;i-=lowbit(i))
	{
		ans+=i[t];
	}
	return ans;
}
int max(int a,int b)
{
	return a>b?a:b; 
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,i,j,ans=0;
	long long m;
	scanf("%d%lld",&n,&m);
	gn=n;
	for(i=0;i<n;++i)
	{
		scanf("%lld",a+i);
	}
	std::sort(a,a+n);
	for(i=0;i<n;++i)
	{
		add(i,a[i]);
	}
	j=0;
	for(i=0;i<n;++i)
	{
		while((i-j+1)*a[i]-(sum(i)-sum(j-1))>m)
		{
			j++;
		}
		ans=max(ans,i-j+1);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
