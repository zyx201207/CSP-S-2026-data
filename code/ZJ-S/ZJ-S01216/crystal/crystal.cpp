#include<bits/stdc++.h>
using namespace std;
int n,a[500005];
long long m;
int f(int k)
{
	int x=a[k],num=0,sum=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=x&&sum+x-a[i]<=m)
		{
			num++;
			sum=sum+x-a[i];
		}
	}
	return num;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin >>a[i];
	}
	int ff=1,l=a[2]-a[1];
	//cout<<l<<endl;
	for(int i=2;i<=n;i++)
	{
		if(a[i]!=a[i-1]+l)
		{
			ff=0;
			break;
		}
	}
	if(ff==1)
	{
		long long sum1=0;
		int i=l,num1=0;
		while(i<=n-1&&sum1<=m)
		{
			sum1+=i;
			//cout<<sum1<<" "<<i<<endl;
			i+=l;
			num1++;
		}
		if(sum1==m)
		{
			cout<<num1;
		}
		else
		{
			cout<<num1-1;
		}
		return 0;
	}
	int num=0,maxx=0;
	for(int i=1;i<=n;i++)
	{
		maxx=max(maxx,f(i));
		//cout<<i<<" "<<f(i)<<endl;
	}
	cout<<maxx;
	return 0;
}
