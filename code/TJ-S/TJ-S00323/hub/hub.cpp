#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int c,t,d[1000002][1000002];
void floyd()
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if(d[k][i]==0)continue;
			for(int j=1;j<=n;j++)
			{
				if(d[k][j]==0) continue;
				if(d[i][k]+d[k][j]<d[i][j])
				d[i]][j]=d[i][k]+d[k][i];
			}
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int n,k1;
		cin>>n>>k1;
		for(int i=1;i<n;i++)
		{
			int u,v;
			d[u][v]=d[v][u]=1;
		} 
		floyd;
		cout<<1<<endl;
	}
	return 0;
}

