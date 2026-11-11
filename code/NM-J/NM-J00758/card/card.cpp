#include<bits/stdc++.h>
using namespace std;
int a[500100],t[500100],w[500100],nxt[500500],pd[500500];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,i,j,k;
	cin>>n>>m;
	for(i=1;i<=n;++i) cin>>a[i];
	for(i=1;i<=n;++i)
	{
		memset(pd,0,sizeof(pd));
		
		for(j=i;j<=n;++j)
		{
			if(pd[a[j]]==0) pd[a[j]]=1,w[a[j]]=j;
			else
			{
				for(k=w[j];k<j;k++)
				{
					pd[a[k]]=0;
				}
				pd[a[j]]=1,w[a[j]]=j;
			}
			
		}
		for(j=1;j<=m;++j) if(pd[j]==1) t[j]++;
	}
	for(j=1;j<=m;++j) cout<<t[j]<<" ";
	return 0;
}
