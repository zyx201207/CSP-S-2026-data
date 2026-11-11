#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],ans;
void dfs(int k,int x,int sum)
{
	if(k>m)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=x;i<=n+k-m;i++)
	{
		if(sum&a[i]<ans) return;
		dfs(k+1,i+1,(k==1?a[i]:sum&a[i])); 
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,[](int x,int y)->bool{return x>y;});
	if(m==1)
	{
		cout<<a[1];
		return 0;
	}
	else if(m==n)
	{
		int ans=a[1];
		for(int i=2;i<=n;i++) ans&=a[i];
		cout<<ans;
		return 0;
	}
	dfs(1,1,0);
	cout<<ans;
	return 0;
}