#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,maxn=INT_MIN;
int a[200100];
void dfs(int x,int c,int sum)
{
	if(x>n&&c<m||sum<maxn)return;
	if(c==m)
	{
		maxn=max(maxn,sum);
		return;
	}
	for(int i=x;i<=n;++i)dfs(i+1,c+1,sum&a[i]);
	return;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	getchar();
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
		getchar();
	}
	for(int i=1;i<=n-m+1;++i)dfs(i+1,1,a[i]);
	cout<<maxn;
	return 0;
}
/*
4 2
3 15 12 12
*/
/*
5 3
31 3 1 15 7
*/
