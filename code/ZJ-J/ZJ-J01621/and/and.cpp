#include<bits/stdc++.h>
#define ll long long
#define db double
const int N=1e6+10,inf=0x3f3f3f3f;
using namespace std;
int n,m,a[N],maxn;
void dfs(int x,int cnt,int ans)
{
	if(x>n)
	{
		if(cnt==m)
		{
			maxn=max(maxn,ans);
			
		}return ;
	}
	
	dfs(x+1,cnt+1,ans&a[x]);
	dfs(x+1,cnt,ans);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int cnt=1;
	for(int i=1;i<=n;i++)
		cnt*=2;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m==1)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
			ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	dfs(2,0,cnt-1);
	dfs(2,1,a[1]);
	cout<<maxn;
	return 0;
}
/*
5 3
31 3 1 15 7
4 2
3 15 12 12
*/
