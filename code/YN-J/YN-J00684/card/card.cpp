#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,ans[N],a[N],vis[N],s[N],top;
void del(int key)
{
	while(s[top]!=key)
	{
		vis[s[top--]]=0;
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int j=1;j<=n;j++)
	{
		memset(vis,0,sizeof vis);
		for(int i=j;i<=n;i++)
		{
			if(!vis[a[i]]) s[++top]=a[i],vis[a[i]]=1;
			else del(a[i]);
		}
		for(int i=1;i<=m;i++)
		{
			ans[i]+=vis[i];
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}