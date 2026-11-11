#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n,k,s[1000001],o[1000001],d[1000001],x,dp[4001][4001];
vector<int>g[1000001];
// void dfs0(int now,int pre)
// {
// 	for(int i=0;i<g[now].size();i++)
// 	{
// 		int nxt=g[now][i];
// 		if(nxt==pre)continue;
// 		dfs(nxt,now);
// 		d[now]=max(d[now],d[nxt]);
// 	}
// 	d[now]++;
// }
// void dfs(int now,int pre)
// {
// 	for(int i=0;i<g[now].size();i++)
// 	{
// 		int nxt=g[now][i];
// 		if(nxt==pre)continue;
// 		dfs(nxt,now);
// 		s[now]+=s[nxt];
// 	}
// 	if(d[now]>=x)s[now]++;
// }
// void dfs1(int now,int pre)
// {
// 	for(int i=0;i<g[now].size();i++)
// 	{
// 		int nxt=g[now][i];
// 		if(nxt==pre)continue;
// 		o[nxt]=o[now]+max(s[now],1)-s[nxt];
// 		dfs1(nxt,now);
// 	}
// }
// bool check()
// {
// 	if(x==0)return false;
// 	dfs(1,0);
// 	dfs1(1,0);

// }
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,ttt;
	cin>>c>>ttt;
	while(ttt--)
	{
		cin>>n>>k;
		for(int i=1;i<=n-1;i++)
		{
			int t1,t2;
			cin>>t1>>t2;
			// g[t1].push_back(t2);
			// g[t2].push_back(t1);
		}
		// dfs0(1,0);
		// int l=0,r=n;
		// while(l+1<r)
		// {
		// 	x=(l+r)/2;
		// 	if(check())r=mid;
		// 	else l=mid;
		// }
		if(n==k)cout<<0<<'\n';
		else if(k>=(n-1)/2)cout<<1<<'\n';
		else if(k==1)cout<<((n-1)/2+1)/2+1<<'\n';
		else cout<<((n-1)/2-k+2)/4+1<<'\n';
	}
}