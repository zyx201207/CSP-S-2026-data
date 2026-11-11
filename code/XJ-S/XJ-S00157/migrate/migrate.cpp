#include<bits/stdc++.h>
using namespace std;
int x[200010]={};
int vis[200010]={};
int vis1[200010]={};
int main() 
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d,ans=0;
		cin>>n>>d;
		x[0]=0;
		vis[0]=0;
		vis1[0]=0;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		int t=d/(x2-x1);
		cout<<n-(2*t-1)<<endl;
	}
	return 0;
}
