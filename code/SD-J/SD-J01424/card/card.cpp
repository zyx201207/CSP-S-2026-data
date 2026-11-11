#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,m,a[N],ans[N];
int main() 
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];	
	for(int i=1;i<=n;i++)
	{
		int ls[N],zym=0,vis[N];
		for(int j=i;j<=n;j++)
		{
			for(int k=1;k<=zym;k++)
				if(ls[k]==a[j])
				{
					for(int l=k;l<=zym;l++)
						ls[l]=0;
					zym=k-1;
				}
			zym++;
			ls[zym]=a[j]; 
		}
		for(int j=1;j<=zym;j++)
			vis[ls[j]]++;
		for(int j=1;j<=m;j++)
			if(vis[i]!=0)
				ans[j]++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
} 
