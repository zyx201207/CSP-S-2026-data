#include<bits/stdc++.h>
using namespace std;//47589 12379 32456 45678
#define int long long
int a[200010],vis[200010],ans;//12352 	
int n,m;
bool cmp(int &a,int &b)
{
	return a>b;
 } 
void dfs(int x,int sum)
{
	if(x>m) {
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=n;++i)
	{
		if(!vis[i])
		{
			vis[i]=1;
			dfs(x+1,a[i]&a[i-1]);
			vis[i]=0;
		}
	}
}
signed main()
{
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	} 
	if(n<2000)
	{
		dfs(1,a[1]);
		cout<<ans;
	}
	else
	{
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=m;++i)
		{
			a[i+1]=a[i]&a[i+1];
		}
		cout<<a[m];
	}
	return 0;
 } 

