#include<iostream>
using namespace std;
int a[200020];
char c[200020];
int main ()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,i,x=0,m=0;
	long long num=0,zs=0,yb=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		zs+=a[i];
	}
	yb=zs/2;
	for(i=1;i<=n;i++)
	{
		yb=yb-a[i];
		if(yb<=0)
		{
		m=i;
		x=yb+a[i];
		break;
		}
	}
	int a1=1,a2=n;
	while(a1<m)
	{
		if(c[a1]==c[a2])
			{
				if(a[a1]>a[a2])
				{
					a[a1]=a[a1]-a[a2];
					a2--;
				}
				else if(a[a1]<a[a2])
				{
					a[a2]=a[a2]-a[a1];
					a1++;
				}
				else if(a[a1]==a[a2])
				{
					a1++;
					a2--;
				}
			}
		else
			if(a[a1]>a[a2])
				{
					a[a1]=a[a1]-a[a2];
					num+=a[a2];
					a2--;
				}
				else if(a[a1]<a[a2])
				{
					a[a2]=a[a2]-a[a1];
					num+=a[a1];
					a1++;
				}
				else if(a[a1]==a[a2])
				{
					num+=a[a1];
					a1++;
					a2--;
				}
	}
	a[a1]=x;
	while(a2>m)
	{
		if(c[a1]==c[a2])
		{
			a[a1]=a[a1]-a[a2];
			a2--;
		}
		else
		{
			a[a1]=a[a1]-a[a2];
			num+=a[a2];
			a2--;
		}
	}
	cout<<num;
	return 0;
}