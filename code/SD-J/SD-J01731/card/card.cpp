#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],l,r,c[500005],cnt[500005];
int main()
{	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			c[i]=a[i];
		}
		r=n;
		for(int j=i;j<=n;j++) 
		{	
			bool f=0;
			for(int k=i;k<=r;k++) 
			{
				 if(c[k]==a[j])
				 {
				 	r=k,f=1;
				 	break;
				 }
			}
			if(!f)
			{
				r+=1,c[r]=a[j];
			}
		}
		for(int j=i;j<=r;j++)cnt[c[j]]++;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;	
} 
