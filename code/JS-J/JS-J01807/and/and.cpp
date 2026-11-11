#include <bits/stdc++.h>
using namespace std;

int n,m,a[200005],maxi = 0;

void dfs(int i,int m1,int ans)
{
	if(m1 == 0)
	{
		maxi = max(ans,maxi);
		return ;
	}
	if(n - i < m1)
		return ;
    dfs(i + 1,m1 - 1,ans & a[i]);
    dfs(i + 1,m1,ans);
	return ;
}

int main()
{
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i < n;i++)
		cin>>a[i];
	dfs(0,m,INT_MAX);
	cout<<maxi<<endl;
	return 0;
}
