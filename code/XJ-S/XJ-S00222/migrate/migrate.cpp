#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int sb,qqqq;
	cin>>sb>>qqqq;
	for(int u=0;u<qqqq;u++)
	{
		int a[100005];
		int m,n,z=0;
		cin>>m>>n;
		for(int i=0;i<m;i++) cin>>a[i];
		for(int i=0;i<m;i++)
		{
			for(int j=i+3;j<m;j++)
		{
			for(int o=i+1;o<j;o++) if((a[o]-a[i]<=n&&a[j]-a[o]<=n)&&(a[o+1]-a[i]<=n&&a[j]-a[o+1]<=n) z++;
		}
		}
		for(int i=0;i<m;i++)
		{
			for(int j=i+3;j<m;j++)
		{
			for(int o=i+1;o<j-1;o++)
			{
				for(int f=o+1;f<j;f++)
			{
				if(a[o]-a[i]<=n&&a[f]-a[o]<=n&&a[j]-a[f]<=n) z++;
			}
			}
		}
		}
		cout<<z<<endl;
	}
} 
