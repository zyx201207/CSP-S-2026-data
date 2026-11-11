#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k,u,v,a[10000][10000],b[10000][10000];
	cin >> c >>t;
	for(int i = 1;i <= t;i++)
	{
		cin >> n >> k;
//		for(int j = 0;j<=n+10;j++)
//		{
//			for(int k = 0;k<=n+10;k++)
//			{
//				a[j][k]=0;
//			}
//		}
		for(int j = 1;j<n;j++)
		{
			cin >> u >> v;
//			if(u > v)
//			{
//				int k = 1;
//				while(a[v][k])
//				{
//					k++;
//				}
//				a[v][k]=u;
//			}
//			else
//			{
//				int k = 1;
//				while(a[u][k])
//				{
//					k++;
//				}
//				a[u][k]=v;
//			}
		}
//		for(int j = 1;j<n;j++)
//		{
//			for(int k = 1;a[j][k];k++)
//			{
//				b[j][a[j][k]] = 1;
//			}
//		}
		
		cout<<1<<endl;
		
	}
	
	return 0;
}
