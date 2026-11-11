#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int m,n,a[N],ans[N];
bool is[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++)
	{
		memset(is,0,sizeof is);
		for(int j=i;j<n;j++)
		{
			for(int k=j;k>=i;k--)
			{
				if(a[k]==a[j]&&is[k]==0)
				{
					for(int y=k;y<j;y++) is[y]=1;
					//break;
				}
			}
		}
		for(int j=i;j<n;j++)
		{
			if(is[j]==0) ans[a[j]]++;
			//cout<<is[j]<<" ";
		}
		//cout<<"\n";
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
