//shuaiyuchenbianxie
#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[200005];
void dfs(int i,int l,long long sum)
{
	if(l==m)
	{
		ans=max(ans,sum);
		return;
	}
	if(i==n+1)return;
	if(a[i]==sum)
	{
		dfs(i+1,l+1,sum&a[i+1]);
	}
	else
	{
		//1xuan
		if(sum==-1)dfs(i+1,l+1,a[i]);
		else dfs(i+1,l+1,sum&a[i+1]);
		//2buxuan
		dfs(i+1,l,sum);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1,0,-1);
	cout<<ans;
	return 0;
}
