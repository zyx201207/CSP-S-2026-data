#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[200005],v[200005],b[200005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long int i,j,z,x,k=1;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		for(j=k;j<i;j++)
		{
			if(a[j]==x)
			{
				for(z=j;z<=k;z++)
				  a[i]=0;
				k=j;
			}
		}
		a[i]=x;
		for(j=1;j<=i;j++)
		  if(a[i]!=0)
		    v[a[i]]++;
	}
	for(i=1;i<=n;i++)
	  if(v[i]!=0)
	    cout<<v[i]<<' ';
	return 0;
} 

