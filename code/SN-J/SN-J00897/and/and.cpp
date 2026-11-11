#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int x=a[i],y=1;
		while(x)
		{
			b[i]+=x%2*y;
			y*=10;
			x/=2;
		}
	}
	int mm=-1;
	for(int i=0;i<=n-(m-1);i++)
	{
		int w=1,v=min(b[i],b[i]+1),z=0,y=1,e=b[i],f=b[i+1],o=0;
		while(v!=0)
		{
			v/=10;
			w++;
		}
		for(int j=1;j<=w;j++)
		{
			if(b[i]%10!=b[i+1]%10)
			z+=0;
			else if(b[i]%10==0)
			z+=0;
			else
			z+=1*y;
			y*=10;
		}
		for(int i=0;i<w;i++)
		{
			for(int j=0;i<i;i++)
			o+=z%10*2;
		}
		mm=max(mm,o);
	}
	cout<<m;
	return 0;
}
