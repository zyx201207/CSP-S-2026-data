#include<bits/stdc++.h>
using namespace std;
int n,m,ans[600000],a[600000],b[600000],c[600000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int d=0;
		for(int j=i;j<=n;j++)
		{
			if(c[a[j]]!=0)
			{
				int t=c[a[j]];
				d=t;
				while(b[t]!=0)
				{
					b[t]=0;
					c[b[t]]=0;
					t++;
				}	
			}
			b[d]=a[j];
			c[a[j]]=d;
			d++;
			cout<<endl;
		}
		for(int i=0;i<d-1;i++)ans[b[i]]++;
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}