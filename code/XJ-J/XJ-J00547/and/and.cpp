#include <iostream>
using namespace std;
int erci(int x)
{
	int y=0;
	int u=2;
	while(x>0)
	{
		y+=x%u;
		x/=2;
		u*=2;
		y*=10;
	}
	return y;
}
int huanyuan(int x,int y,int p)
{
	if(x==y)
	{
		retun a[p];
	}
}
int main()
{
	freopen("and.in","m",stdin);
	freopen("and.out","r",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	int b[n];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=erci(a[i]);
	}
	int max=0;
	for(int i=1;i,=n-1;i++)
	{
		if(huanyuan(a[i],a[i+1],i)>max)
		{
			max=huanyuan(a[i],a[i+1],i);
		}
	}
	cout<<max;
}