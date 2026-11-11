#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans=0,a[200001];
void dfs(int cen,int id,long long sm)
{
	if(cen>=m)
	{
		ans=max(ans,sm);
		return;
	}
	for(int i=id+1;i<=n;i++)dfs(cen+1,i,sm&a[i]);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)dfs(1,i,a[i]);
	cout<<ans<<endl;
	return 0;
}