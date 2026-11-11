#include <bits/stdc++.h>
using namespace std;
long long n,m,a[210000],p[210000],f[210000],q[210000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int k=0;
		memset(f,0,sizeof(f));
		memset(p,0,sizeof(p));
		for(int j=i;j<=n;j++)
		{
			if(f[a[j]]==0) f[a[j]]=1,p[++k]=a[j];
			  else 
			  {
			  	int pq=0;
			for(int t=k;t>=1;t--)
			{
			  	if(p[t]==a[j]) 
			  	{
			  		k=t;
			  		pq=1;
			  		break;
				}
			}
			if(pq==0) p[++k]=a[j];			  	
			  }
		}
		memset(f,0,sizeof(f));
		for(int j=1;j<=k;j++) if(f[p[j]]==0) q[p[j]]++,f[p[j]]=1;
	}
	for(int i=1;i<=m;i++) cout<<q[i]<<" ";
}