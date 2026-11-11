#include<bits/stdc++.h>
using namespace std;
int c,t,a[20][20],ways,vis[20];
void dfs(int k,int now,int neng,int arrival,int step)
{
	if(now==arrival){
		if(vis[arrival]==step)
		{
			ways++;
		}
		else if(vis[arrival]>step)
		{
			ways=1;
		}
		return;
	}
	for(int i=now;i<=now+neng;i++)
	{
		if(a[k][i]!=INT_MAX){
			dfs(k,i,neng,arrival,step+1);
		}
	}
}
int main()
{
//	鸟儿单向双向都可以飞翔 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<=20;j++)
		{
			a[i][j]=INT_MAX;
		}
	}
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		int ans=0,n,d;
		cin>>n>>d;
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
		for(int j=2;j<=n;j++)
		{
			ways=0;
			dfs(j,1,d,j,0);
			if(ways==2){
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
}
