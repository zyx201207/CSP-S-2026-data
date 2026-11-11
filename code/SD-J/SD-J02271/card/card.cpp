#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);	
int a,zn,n[10001],m,l=0,b[10001],z=0,g=1,oj=0,tj=0,sj=0,oz=0,tz=0,sz=0;
cin>>a;
for(int e=0;e<a;e++)
{
l=0;cin>>n[e];	
for(int i=0;i<a;i++)
{
	
	l++;
	for(int j=0;j<l;j++)
	{
		if(n[j]==n[i])
		{
			b[z]=n[i];
		}
	}		
}
g++;
for(int k=0;k<=l;k++)
{
	if(b[k]==1)
	{
		if(oz=0)
		{
			oj=oj+1;
			oz=0;
		}	
	}
	if(b[k]==2)
	{
		if(tz=0)
		{
			tj=tj+1;
			tz=0;
		}	
	}
	if(b[k]==3)
	{
		if(sz=0)
		{
			sj=sj+1;
			sz=0;
		}	
	}
}
}
cout<<oj<<tj<<sj;
return 0;
}
