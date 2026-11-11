#include<bits/stdc++.h>
using namespace std;
int a[200100],ans=0,n,m;
void dfs(int k,int c,int sum)
{
	if(c==0)
	{
		if(ans<sum)
		{
			ans=sum;
		}
		return;
	}
	if(k>n) 
	{
		return;
	}
	dfs(k+1,c,sum);
	if(c==m) dfs(k+1,c-1,a[k]);
	else dfs(k+1,c-1,sum&a[k]);
	return;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int i;
	cin>>n>>m;
	for(i=1;i<=n;++i) cin>>a[i];
	dfs(1,m,0);
	cout<<ans;
	return 0;
}
