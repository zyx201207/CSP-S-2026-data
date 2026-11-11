#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[300000];
bool used[300000];
void dfs(int g,int k,long long h)
{
	if(k==m)
	{
		ans=max(ans,h);
		return;
	}
	if(g>n)return;
	dfs(g+1,k+1,h&a[g]);
	if(n-g+1>m-k)dfs(g+1,k,h);
}
int main() 
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0,pow(2,31)-1);
	cout<<ans;
	return 0;
}
