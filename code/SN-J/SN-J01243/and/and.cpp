#include<bits/stdc++.h>//... 
using namespace std;
freopen("and.in","r",stdin)
freopen("and.out","w",stdout)
long long e1[35]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648};//2^31 
long long se(long long x)//十转二 
{
	long long y[35]={};
	int s=0;
	for(int i=30;i>=0;i--) 
	{
		if(x>=e1[i])
		{
			x-=e1[i];
			y[i]=1;
		}
	}
	for(int i=0;i<=30;i++)
	{
		return y[i];
	}
}
/* 
long long es(long long y[35])//二转十 
{
	int l=strlen(y),x=0;//有误 
	for(int i=0;i<=l;i++)
	{
		if(y[i]==1)
		{
			x+=e1[i];
		}
	}
	return x;
}
long long ad(long long x[35],long long y[35])//按位与的值 
{
	int aa[35]={},bb=0;
	for(int i=1;i<=30;i++)
	{
		if(x[i]==y[i]);
		aa[i]=1;
	}
	bb=es(aa[35]);
	return bb;
}
*/
int main()
{
	int n,m,t=2147483648,p=0,a;
/*
	struct a//结构体咋定义来着？ 
	{
		long long alls[200005];
		long long alle[200005];
	}int z[200005];
*/
	cin>>n>>m;
/*
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].alls;//是这么用的么...我咋记得是a.all[200005]嘞？
		a[i].alle=se(a[i].alls);
	} 
*/
/*
	for(int i=1;i<=n;j++)//排列组合
	{
		for(int j=1;j<=n;k++)
		{	
			
			p=max(p,)
		}
	}
	
	cout<<p;
*/
	if(m==1)//做不出来了，骗点分... 能骗到吗... 
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a;
			p=max(p,a);	
		}
		cout<<p;
	}
	return 0;
}
