#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int man=500005;
int c,n,m,d,q,k[505],deg[man];ll w[man],dp[505][505],lim=1000000000000000000ll;
vector<pair<int,ll> >s[man];vector<pair<int,ll> >r[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) dp[i][j]=(i==j?0:lim);
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int now;ll cost;cin>>now>>cost;
			s[now].push_back((pair<int,ll>){i,cost});
			r[i].push_back((pair<int,ll>){now,cost});
			deg[now]++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<k[i];j++){//5*10^5，遍历一条地铁的 k 个站点 
			int loc=r[i][j].first;
			for(int zz=0;zz<deg[loc];zz++)
				dp[i][s[loc][zz].first]=min(dp[i][s[loc][zz].first],r[i][j].second+s[loc][zz].second);
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int zz=1;zz<=n;zz++)
				dp[j][zz]=min(dp[j][zz],dp[j][i]+dp[i][zz]);
	while(q--){
		int l,r;ll ans=lim;cin>>l>>r;
		for(int i=0;i<deg[l];i++)
			for(int j=0;j<deg[r];j++)
				ans=min(ans,dp[s[l][i].first][s[r][j].first]+s[l][i].second+s[r][j].second);
		ans=ans+w[l]+w[r];
		cout<<ans<<'\n';
	}
	return 0;
}
//Oct31==Dec25?
/*
注意到，一条地铁到其所有经过的站点时间贡献为 0
本题只有换乘是重要的
第 i 条地铁换乘到第 j 条只关心其所有能换到 j 的地铁站的最小值 
显然是对的
预处理每条地铁之间换乘时间的最小值
对 q 次询问，每次在起点站的所有换乘线路中枚举最开始选哪条
这个次数是 d^2=400 的，共计算 4*10^7 次，感觉有点跑不过啊
大方向是对的，因为用到 d 了
预处理换乘代价的做法可以用 floyd 复杂度 n^3
15:23 写起耍 
15:32 好烦啊 
16:05 写完了，但是没过 
16:10 通过所有大样例 
*/