#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500050],k[550],a[500][70000],t[500][70000],x,y,tim,stk[500050][21],t1[550]={1},vis[500000],visk[550],ans;
int dfs(int c)
{
	if(c==y)
	{
		ans=min(tim,ans)
		return 0;
	}
	for(int i=1;i<=20;i++)
	{
		if(stk[c][i]!=0&&visk[stk[c][i]]==0)
		{
			visk[stk[c][i]]=1;
			vis[c]=1;
			for(int j=1;j<=k[stk[c][i]];j++)
			if(a[stk[c][i]][j]!=c)
			dfs(a[stk[c][i]][j]);
			vis[c]=1;
			visk[stk[c][i]]=0;
		}
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway1.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			stk[ a[ i ][ j ] ][ t1[ a[ i ][ j ] ]++] = i;
		}
	}
	for(int i=1;i<=q;i++)
	{
		ans=0x3f3f3f;
		tim=0;
		cin>>x>>y;
		vis[x]=1; 
		tim +=w[x];
		dfs(x);
		tim+=w[y];
		vis[x]=0; 
		cout<<ans<<'\n';
	}
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i];j++)
		{
			cout<<t[i][j]<<" ";
		}
		cout<<'\n';
	}*/
	return 0;
}
