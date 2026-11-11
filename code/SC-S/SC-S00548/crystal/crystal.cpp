#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long ans=0,n,m,a[N],b[N];
void dfs(int c,int ma)
{
	if(c==0||ma==n)
	{
		ans= ans < ma ? ma : ans;
		return;
	}
	if(ma>ans)
	{
		ans=ma;
	} 
	for(int i=1;i<=n;i++)
	{
		b[a[i]]--;
		a[i]++;
		b[a[i]]++;
		dfs(c-1,b[a[i]]);
		b[a[i]]--;
		a[i]--;
		b[a[i]]++;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]]++;
	}
	dfs(m,0);
	cout<<ans;
	return 0;
} 
