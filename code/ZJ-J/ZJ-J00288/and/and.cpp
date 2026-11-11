#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200005],mx=INT_MIN;
void dfs(ll k,ll sum,ll num)
{
	if(num==m) mx=max(mx,sum);
	if(k>n||num==m) return ;
	if(num==0) dfs(k+1,a[k],num+1);
	else dfs(k+1,sum&a[k],num+1);
	dfs(k+1,sum,num);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.in","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		ll maxx=INT_MIN;
		for(int i=1;i<=n;i++)
		{
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	else if(m==n)
	{
		ll maxx=INT_MIN;
		for(int i=1;i<=n;i++)
		{
			maxx=maxx&a[i];
		}
		cout<<maxx;
		return 0;
	}
	dfs(1,0,0);
	cout<<mx;
}
