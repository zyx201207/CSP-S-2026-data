#include<bits/stdc++.h>
using namespace std;
int a[550];
int s[505][505];
bool flag[505];
int tt;
int t1;
int c,n,m,d,q;
void dfs(int x,int y,int t,int p)
{
	flag[x]=1;
	if(x==y)
	{
		tt=min(t+t1,tt);
		return;
	}		
	for(int i=1;i<=n;i++)
		if(s[x][i]!=0&&flag[i]==0)
		{
			if(p!=s[x][i])
				dfs(i,y,t+t1+t1,s[x][i]);
			else
				dfs(i,y,t,s[x][i]);
		}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);	
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		while(x--)
		{
			int k=0,w;
			cin>>w>>t1;	
			if(k!=0)	
			{
				s[k][w]=i;
				s[w][k]=i;
			}	
			k=w;
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		tt=1e9;
		memset(flag,0,sizeof(flag));
		dfs(x,y,a[x]+a[y]+t1,1);
		cout<<tt<<'\n';
	}
	return 0;
}