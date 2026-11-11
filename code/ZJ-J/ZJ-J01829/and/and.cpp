#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,a[N],m,ans;
void dfs(int c,int sum,int st)
{
	if(c==m)
	{
		ans=max(ans,sum); 
		return;
	}
	for(int i=st;i<=n;i++)
	{
		int x;
		if(c==0)
		x=a[i];
		else x=sum&a[i];
		dfs(c+1,x,i+1);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==m)
	{
		ans=a[1]&a[2];
		for(int i=3;i<=n;i++)
		ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	dfs(0,0,1);
	cout<<ans;
	return 0;
}