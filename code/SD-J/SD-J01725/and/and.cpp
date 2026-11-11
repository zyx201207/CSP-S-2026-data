#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m;
int a[N],dp[N];
bool vis[N]={0};
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	memset(dp,0,sizeof(0));
	int maxn=-1e12;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);	
	}
	sort(a+1,a+1+n);
	auto it=lower_bound(a+1,a+1+n,maxn)-a;
	vis[it]=1;
	dp[1]=maxn;
	for(int i=2;i<=n;i++){
		int t=-123;
		int w=it;
		if(i>m)break;
		//t=dp[i]&a[1];
		for(int j=1;j<=n;j++){
			if(vis[i])continue;
			dp[i]=max(dp[i-1]&a[j],t);
			if(t!=dp[i])w=j;
			t=dp[i];
		}
		vis[w]=1;
	}
	cout<<dp[m];
	return 0;
}
