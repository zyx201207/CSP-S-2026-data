//3
#include<bits/stdc++.h>
using namespace std;
//#define int long long
long long n,m,a[210000],ans;
void dfs(int x,int cnt,long long sum)
{
	if(cnt==m)
	{
		ans=max(ans,sum);
		return ;
	}
	if(cnt>m || x>n) return ;
	dfs(x+1,cnt+1,sum&a[x]);
	dfs(x+1,cnt,sum);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(0,0,(1<<31)-1);
	cout<<ans;
	return 0;
}