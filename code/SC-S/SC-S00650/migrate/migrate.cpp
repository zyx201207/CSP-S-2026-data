#include<bits/stdc++.h>
using namespace std;
int x[2000010];
int main()
{
	freopen("migratein","r",stdin);
	freopen("migrate.out","w",stdout);
	int c ,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		int cnt=0;
		int n,d;
		cin>>n>>d; 
		for(int j=1;j<=n;j++)
		{
			cin>>x[i];
		}
		for(int k=1;k<=n-2;k++)
		{
			for(int l=k+2;l<=n;l++)
			{
				if(x[l]-x[k]>d&&x[l]-x[k]<=2*d)
				{
					cnt++;
				}
			}
		} 
		cout<<cnt<<endl; 
	}
	return 0;
} 