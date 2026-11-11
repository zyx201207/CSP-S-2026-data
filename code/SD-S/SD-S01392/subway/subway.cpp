#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;//.first:a .second:t
const int N=505,M=5e5+5;
ll c,n,m,d,q;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过、出行计划数
ll w[M],k[N];
vector<pll> a[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++)cin>>w[i];
	for(int i=1; i<=n; i++){
		cin>>k[i];
		for(int j=1; j<=k[i]; j++){
			ll A,T;
			cin>>A>>T;
			a[i].push_back({A,T});
		} 
	}
	for(int i=1; i<=q; i++){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]<<'\n';
	}
	return 0;
}
/*
世界问 你是谁 来自哪 
请回答 爱什么 梦什么 去何方
请回答 答案有 一百年的时光

我来自硝烟中 课桌旁的太阳
他和它 宣的誓 赢得仗
来自那 燃烧的 和我一样的年华
...... 
*/ 
