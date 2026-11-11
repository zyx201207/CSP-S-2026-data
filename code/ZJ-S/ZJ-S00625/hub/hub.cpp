#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,f[2000005];

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin>>c>>t;
	while (t--)
	{
		cin>>n>>k;
		int u,v,l=0;
		for (int i=1;i<=n;i++) f[i]=0;
		for (int i=1;i<n;i++)
		{
			cin>>u>>v;
			int p=f[v];
			f[v]=max(f[v],f[u]+1);
			f[u]=max(f[u],p+1);
		}
		for (int i=1;i<=n;i++)
		{
			l=max(l,f[i]);
		}
		cout<<(l+1)/k<<endl;
	}
	
	return 0;
}
