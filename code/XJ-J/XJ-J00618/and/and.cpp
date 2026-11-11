#include<bits/stdc++.h>
using namespace std;
int a[200005],n,m,y,MAX,flag=0;
int sum=0;
void f(int x,int s,int step)
{
	if(step==m)
	{
		if(s>sum)
		{
			sum=s;
		}
		return ;
	}
	for(int i=x+1;i<=n-m+step+1;i++)
	{
		y=s&a[i];
		f(i,y,step+1);
	}
}
int main()
{ 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>MAX)
		{
			MAX=a[i];
		}
		if((a[i]^0)!=a[i]) flag=1;
	}
	if(m==n)
	{
		sum=a[1];
		for(int i=2;i<=n;i++)
		{
			sum=sum&a[i];
		}
		cout<<sum;
		return 0;
	}
	if(m==1)
	{
		cout<<MAX;
		return 0;
	}
	if(flag==0)
	{
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}
	for(int i=1;i<=n-m+1;i++)
	{
		f(i,a[i],1);
	}
	cout<<sum;
	return 0;
}
