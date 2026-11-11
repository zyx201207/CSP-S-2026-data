#include<bits/stdc++.h>
using namespace std;
int a[200005],vis[200005],m,n,ma=-2e9;
void dfs(int x,int s)
{
	if(s==m)
	{
		ma=max(ma,x);
		return;
	}
	for(int i=0;i<n;i++)
		if(!vis[i])
		{
			vis[i]=true;
			dfs((x==-1)?a[i]:(x&a[i]),s+1);
			vis[i]=false;
		}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	dfs(-1,0);
	printf("%d",ma);
	return 0;
}

