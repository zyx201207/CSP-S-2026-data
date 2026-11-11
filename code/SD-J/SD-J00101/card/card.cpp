#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],c[300005],x[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int h=1;
		memset(x,0,sizeof(x));
		for(int j=i;j<=n;j++)
		{
			if(x[a[j]]!=0)
			{
				
				int s=x[a[j]];
				for(int k=x[a[j]];k<=h;k++)x[a[k]]=0;
				h=s;
				x[a[j]]=h++;
				
			}
			else x[a[j]]=h++;
			
		}
		for(int j=1;j<=m;j++)
		{
			if(x[j]!=0)c[j]++;
		}
	}
	for(int j=1;j<=m;j++)
	{
		cout<<c[j]<<" ";
	}
	return 0;
} 
