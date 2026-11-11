#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long a[200001];
int b[200001];
int m,n,a0;
long long ans=0;
long long qp(int x,int y)
{
	if (y==1) return x;
	int bb=qp(x,y/2);
	if (y%2==0) return bb*bb;
	else return bb*bb*x;
}
void zhuan(int a1,int x)
{
	for (int i=0;;i++)
	{
		a[x]=a0%2*qp(10,i);//由低位到高位 
		a0=a0%2;
	}
	return;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
	  cin>>a0;		
	}
///	for (int i=qp(2,30);i>=1;i/2)
//	{
//		for (int j=1;j<=n;j++)
//		{
			if (a[j]/i==1) b[j]++;
//		}
	}
	sort(a+1,a+1+n);
	cout<<a[1];
	return 0;
}
