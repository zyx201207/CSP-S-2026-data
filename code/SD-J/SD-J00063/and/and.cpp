#include<bits/stdc++.h>
using namespace std;
long long a[200005],ans;
int n,m;
void dfs(long long sum,int x,int k)
{
	if(k==m)
	{
		ans=max(ans,sum);
		return;
	}
	if(x==n-1)return;
	dfs(sum,x+1,k);
	dfs(sum&a[x],x+1,k+1);
	return;
}
bool cmp(long long x,long long y)
{
	if(x>y)return true;
	else return false;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++)
	{
		dfs(a[i],0,0);
	}
	cout<<ans<<"\n";
	return 0;
}
