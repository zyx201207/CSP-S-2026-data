#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
long long andd(int x,int y)
{
	int t=1;
	long long summ=0;
	while(x>0 && y>0)
	{
		if(x%2==1 && y%2==1)
		{
			summ+=t;
		}
		t*=2;
		x/=2,y/=2;
	}
	return summ;
}
int main()
{
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(m==1)
	{
		long long num=-10000;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>num) num=a[i];
		}
		printf("%d",num);
	}
	else if(n==m)
	{
		long long num=a[1];
		for(int i=2;i<=n;i++)
		{
			num=andd(num,a[i]);
		}
		printf("%d",num);
	}
	return 0;
}
