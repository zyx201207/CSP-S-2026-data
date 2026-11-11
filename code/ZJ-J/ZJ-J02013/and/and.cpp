#include<bits/stdc++.h>
using namespace std;
int a[100005];
int ans=-1,m,n;
void dfs(int x,int y,int z)
{
	if(z==m)
	{		
		if(y>ans)
		{
			ans=y;
		}
		return;	
	}	
	for(int i=1;i<=n-x+1;i++)
		dfs(x+i,y&=a[x+i],z+1);
	return;
}
int main()
{
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(0,1048575,0);
	cout<<ans;
	return 0;
}