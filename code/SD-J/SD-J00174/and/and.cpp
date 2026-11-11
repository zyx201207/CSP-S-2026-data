#include<bits/stdc++.h>
#define MAXN 200005
#define IOS ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);

using namespace std;

int n,m,a[MAXN],ch[MAXN],ans=-1;
bool vis[MAXN];

void dfs(int pos,int pre)
{
	if(pos==m+1)
	{
		int k=(ch[1]&ch[2]);
		for(int i=3;i<=m;i++)
		{
			k=(k&ch[i]);
		}
		ans=max(k,ans);
		
		return ;
	}
	
	for(int i=pre;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			ch[pos]=a[i];
			dfs(pos+1,i+1);
			vis[i]=0;
		}
	}
}

int main()
{
	IOS
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	dfs(1,1);
	
	cout<<ans;
		
	return 0;
}
