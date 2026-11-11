#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int r[300005];
bool v[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int nn=n;
	bool ff=1;
	for(int i=1;i<=nn;i++)
	{
		cin>>a[i],b[i]=a[i];
		if(a[i]<a[i-1]) ff=0;
	} 
	if(ff)
	{
		for(int i=n;i>=1;i--)
		{
			if(!v[a[i]])
			{
				r[a[i]]=i;
				v[a[i]]=1;
			} 
		}
		for(int i=1;i<=m;i++) cout<<r[i]<<" ";
		return 0;
	}
	for(int t=1;t<=nn;t++)
	{	
		for(int i=1;i<=nn;i++) b[i]=a[i],v[i]=0;
		for(int i=t;i<=nn;i++)
		{ 
			for(int j=t;j<=n;j++)
			{
				if(b[j]==a[i])
				{
					n=j-1;	
					break;
				}
			}
			n++;
			b[n]=a[i];
		}
		for(int i=t;i<=n;i++)
		{	
			if(!v[b[i]]) r[b[i]]++,v[b[i]]=1;	
		}
		n=nn;
	}
	for(int i=1;i<=m;i++) cout<<r[i]<<" ";
	return 0;
}