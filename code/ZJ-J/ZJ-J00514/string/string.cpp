#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long x=0;
	int n,l=0,x1=1,x2,k1=1,k2;
	cin>>n;
	int a[n+10];
	char c[n+10];
	c[0]='A';
	for(int i=1;i<=n;i++)
	{
		int a1;
		char c1;
		cin>>a1>>c1;
		if(c1==c[l])a[l]+=a1;
		else
		{
			l++;
			a[l]=a1;
			c[l]=c1;
		}
	}
	x2=l;
	k2=a[l];
	while(1)
	{
		if(a[x1]>a[x2])
		{
			if(c[x1]!=c[x2])x+=a[x2];
			x2--;
			k2=a[x2];
			k1+=a[x2+1];
			a[x1]-=(k1-1);
		}
		else if(a[x1]<a[x2])
		{
			if(c[x1]!=c[x2])x+=a[x1];
			x1++;
			k1=1;
			k2-=a[x1-1];
			a[x2]=k2;
		}
		else
		{
			if(c[x1]!=c[x2])x+=a[x1];
			x1++;
			k1=1;
			x2--;
			k2=a[x2];
		}
		if(x1-x2>=0)break;
	}
	cout<<x;
	return 0;
}
