#include<iostream>
#include<cstdio>
using namespace std;
int u[4005],v[4005],g[4005][4005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int sum=0;
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			cin>>u[i]>>v[i];
			g[u[i]][v[i]]=1;
			g[v[i]][u[i]]=1;
		}
		for(int i=1;i<=n;i++)
		{
			if(g[1][i]==1) sum++;
		}
		cout<<sum<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
