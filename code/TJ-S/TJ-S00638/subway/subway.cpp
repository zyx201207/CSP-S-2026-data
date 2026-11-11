#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[50];
int a[510][510];
int t[520][520];
int main()
{
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=2*k;j++)
		{
			int x;
			cin>>x;
			if(j%2!=0)
			{
				a[i][j]=x;
			}
			else
			{
				t[i][j]=x;
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int start,over;
		cin>>start>>over;
		int ans=0;
		ans+=w[start]+w[over];
		cout<<ans<<'\n';
	}
	return 0;
}
