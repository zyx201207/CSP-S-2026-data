#include<bits/stdc++.h>
using namespace std;
int a[500010],p[300010],n,m,rt[500010],b[300010];
int pd()
{
	for(int i=1;i<=n;i++)
	  if(a[i]<a[i-1]) return 0;
	return 1;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(pd())
	{
		for(int i=1;i<=n;i++)
		  if(a[i]==a[i-1]) p[a[i]]++;
		    else p[a[i]]=p[a[i]-1]+1;
		for(int i=1;i<=m;i++) cout<<p[i]<<" ";
	}
	else if(n<=5000)
	{
		for(int i=1;i<=n;i++)
		{
			memset(b,0,sizeof(rt));
			int u=1;
			for(int j=i;j<=n;j++)
			{
		  		if(b[a[j]]==0||b[a[j]]>=u)
				{
				  	rt[u]=a[j];
					b[a[j]]=u;
					u++;
				}
		  		else if(b[a[j]]<u) u=b[a[j]]+1;
		  	}
		  	for(int j=1;j<=u;j++) p[rt[j]]++;
		}
		for(int i=1;i<=m;i++) cout<<p[i]<<" ";
	}
	return 0;
} 
