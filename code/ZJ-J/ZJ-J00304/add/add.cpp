#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxx;
int add(int xx,int yy)
{
	int cnt=0;
	int w=1;
	while(xx&&yy)
	{
		cnt+=w*min(xx%2,yy%2);
		xx/=2;
		yy/=2;
		w*=2;
	}
	return cnt;
}
void dfs(int x,int l,int ans)
{
	if(l==m)
	{
		maxx=max(maxx,ans);
		return;
	}
	if(x>n)
	{
		return;
	}
	if(l==0)
	{
		dfs(x+1,l+1,a[x]);
	}
	else
	{
		dfs(x+1,l+1,add(ans,a[x]));
	}
	dfs(x+1,l,ans);
	return;
}
int main()
{
	freopen("add.in","r",stdin);
	freopen("add.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<maxx;
	return 0;
}