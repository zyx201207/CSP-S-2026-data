#include<bits/stdc++.h>
using namespace std;
struct S
{
	int num;
	string c;
};
S a[2005];
int n;
long long l,mid,ans,x[2002],y,z,w;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if (n==1)
	{
		cout<<0;
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		cin>>a[i].num>>a[i].c;
		l+=a[i].num;
	}
	mid=l/2;
	ans=mid;
	x[0]=0;
	for (int i=n;i<=mid;i++)
	{
		x[i]=a[i].num+x[i-1];
	}
	for (int i=1;i<=mid;i++)
	{
		for (int j=w;j<=mid;j++)
		{
			if (a[i].num<=x[j])
			{
				y=j;
				w=y;
				break;
			}
		}
		z=a[i].num;
		for (int j=1;j<=y;j++)
		{
			if ((a[i].c==a[j].c)&&(z>=a[j].num))
			{
				ans-=a[j].num;
				z-=a[j].num;
			}
			else if ((a[i].c==a[j].c)&&(z<a[j].num))
			{
				ans-=z;
			}
		}
	}
	cout<<ans;
	return 0;
}
