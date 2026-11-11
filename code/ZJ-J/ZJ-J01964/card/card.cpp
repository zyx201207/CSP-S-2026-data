#include<bits/stdc++.h>
using namespace std;
int ok=1,n,m,a[12502051],b[200005],i,j,t[200005],k=0,vis[200005],nn,t2[200005],sum=0,ans=0;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	nn=n;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=2;i<=nn;i++)
	for(j=i;j<=nn;j++)
	a[++n]=a[j];
	for(i=1;i<=n;i++)
	{
		if(ok==1)
		{
		sum+=(nn-ans);
		ok=0;
	}
		if(t[a[i]]==0)t[a[i]]=k+1,b[++k]=a[i];
		else
		{
			for(j=t[a[i]]+1;j<=k;j++)t[b[j]]=0,b[j]=0;
			k=t[a[i]];
		}
		if(sum==i)
		{
		for(j=1;j<=k;j++)
		{
			if(t2[b[j]]==0)
			{
				t2[b[j]]=1;
				vis[b[j]]++;
			}
		}
		k=0;
		memset(b,0,sizeof(b));
		memset(t,0,sizeof(t));
		memset(t2,0,sizeof(t));
		ans++;
		ok=1;
	}
}
	for(i=1;i<m;i++)cout<<vis[i]<<" ";
	cout<<vis[m];
	return 0;
}
