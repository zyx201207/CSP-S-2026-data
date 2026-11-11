#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100005],n,m;
ll dfs(ll x,ll y)
{
	if(x>n) return 0;
	if(y>m) return 0;
	if(x==n && y<m) return 0;
	if(y==m) return a[y];
	return max(dfs(x+1,y),dfs(x+1,y+1)&a[y]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	cout<<dfs(1,0);
	return 0;
}