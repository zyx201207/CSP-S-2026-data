#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr bool online=1;
//n<=500 m<=5e5 lim<=20 k<=1e5
int c,n,m,lim,k,w[500005],d[505][505];
vector<pair<int,int>>mygo[500005];
inline void dtmin(int l,int r,int v){
	d[l][r]=d[r][l]=min(d[l][r],v);
}
signed main(){
	if(online)
		freopen("subway.in","r",stdin),
		freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>n>>m>>lim>>k;
	for(int i=1;i<=m;++i) cin>>w[i];
	/*
	要求解的是总步行时间最少
	因此我们可以这样考虑：
	由于乘坐地铁本身不需要时间，所以直接缩点。
	也就是说如果我能够以地铁线路作为最核心的东西进行全源最短路
	则时间复杂度会非常有可能是正确的
	注意到每一个站还有最大经过数量，而且 m*lim <= 1e7
	所以我们考虑这样一种策略：
	
	每一个站，途径这个站的地铁之间两两直接连边
	显然这一步的代价为 m/lim * lim^2 = m*lim

	求解一下地铁间的互相到达的最小代价，使用 floyd 即可
	这一步的代价为 n^3 = 1.25e8
	但是内存连续 L1 Cache + Pre-read 飞快

	求答案的时候，我们枚举在两个站分别上哪一个地铁
	显然这一步的代价为 k*lim^2 = 4e7

	这绝对是正解，CSPS T2 哪有 BS 的神仙东西难？？？
	*/
	memset(d,0x0f,sizeof d);
	for(int i=1,c;i<=n;++i){
		cin>>c; d[i][i]=0;
		for(int j=0,l,r;j!=c;++j)
			cin>>l>>r,mygo[l].emplace_back(i,r);
	}
	for(int i=1;i<=m;++i)
		for(int j=0;j!=mygo[i].size();++j)
			for(int k=j+1;k!=mygo[i].size();++k)
				dtmin(mygo[i][j].first,mygo[i][k].first,mygo[i][j].second+mygo[i][k].second);
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	for(int i=1,l,r,ans;i<=k;++i){
		cin>>l>>r; ans=1e18;
		for(const auto&v1:mygo[l])
			for(const auto&v2:mygo[r])
				ans=min(ans,w[l]+w[r]+v1.second+v2.second+d[v1.first][v2.first]);
		cout<<ans<<"\n";
	}
	return 0;
}
//1508 passed all samples exp 100pts.
//1510 optimized floyd
//1513 passed full check
//1514 passed all samples exp 100pts.
//biggest suggested