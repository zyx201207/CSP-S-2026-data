#include<bits/stdc++.h>
using namespace std;
int a[200005];
int i,j,x,y;
long long int sum=0;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	i=1;
	j=n;
	x=0;
	y=0;
	while(i<j)
	{
		if((a[i]-x)<(a[j]-y))
		{
			if(c[i]!=c[j])
			{
				sum+=a[i]-x;
			}
			y=y+a[i]-x;
			i++;
			x=0;
		}
		else if((a[i]-x)>(a[j]-y))
		{
			if(c[i]!=c[j])
			{
				sum+=a[j]-y;
			}
			x=x+a[j]-y;
			j--;
			y=0;
		}
		else
		{
			if(c[i]!=c[j])
			{
				sum+=a[i]-x;
			}
			i++;
			j--;
			x=0;
			y=0;
		}
	}
	cout<<sum;
	return 0;
}
