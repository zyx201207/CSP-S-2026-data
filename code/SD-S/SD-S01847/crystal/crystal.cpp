#include<bits/stdc++.h>
using namespace std;
long long a[500001],b[500001];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long m,ars=0;
	int n,maxx=0,t=0,max=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	for(int j=1;j<=n;j++)
	{		b[j]=0;}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i]>=a[j])
			   b[j]=a[i]-a[j];
			else
			   b[j]=-1;
			  
		}
		for(int j=1;j<=n;j++){
		  if(b[j+1]<b[j])
			{
				t=b[j];
				b[j]=b[j+1];
				b[j+1]=t;
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(ars<=m&&b[j]!=-1)
			{
			  ars+=b[j];
			  max++;
		}
		}
		if(max>maxx)
		  maxx=max;
	max=0;
	ars=0; 
	}
	cout<<maxx;
	return 0;
}
