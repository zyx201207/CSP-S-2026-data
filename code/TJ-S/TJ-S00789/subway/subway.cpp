#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll mp[510][510];
vector <pair<ll,ll> > a[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll c,n,m,d,q;
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q); 
	for(ll i = 0;i < 510;i++){
		for(ll j = 0;j < 510;j++){
			if(i == j){
				mp[i][j] = 0;
			}else{
				mp[i][j] = 10000000000000;
			}
		}
	}
	ll w[m+1];
	for(ll i = 1;i <= m;i++){
		scanf("%lld",&w[i]);
	} 
	for(ll i = 1;i <= n;i++){
		ll x;
		scanf("%lld",&x);
		for(ll j = 1;j <= x;j++){
			ll now_point,now_downup_distance;
			scanf("%lld%lld",&now_point,&now_downup_distance);
			for(ll k = 0;k < a[now_point].size();k++){
				ll s0 = a[now_point][k].first;
				ll t0 = a[now_point][k].second;
				mp[s0][i] = min(mp[s0][i],t0+now_downup_distance);
				mp[i][s0] = mp[s0][i];
			} 
			a[now_point].push_back(make_pair(i,now_downup_distance));
		}
	}
	for(ll k = 1;k <= n;k++){
		for(ll i = 1;i <= n;i++){
			for(ll j = 1;j <= n;j++){
				mp[i][j] = min(mp[i][j],mp[i][k]+mp[k][j]);
				mp[j][i] = mp[i][j];
			}
		}
	}
	for(ll i = 1;i <= q;i++){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		ll ans = 10000000000000;
		for(ll j = 0;j < a[x].size();j++){
			for(ll k = 0;k < a[y].size();k++){
				ans = min(ans,w[x]+w[y]+a[x][j].second+a[y][k].second+mp[a[x][j].first][a[y][k].first]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
//16:29  感觉T2没有想象地那么简单
//16:29  我还是开始写赛时经过吧
//16:30  能把T1写出来已经挺好了，10分钟看出做法但写程序写了一个半小时......
//16:31  这题这么良心还把测试点编号在输入中告诉我了 
//16:35  真费劲啊......不想写了
//16:47  突然想到可以把每条线路整个看成一个点然后换乘站是带权无向边，两个点之间建图时只保留最小边，这样就没有重边，然后跑一遍floyd！好像能拿100？ 
//17:11  代码写出来了，应该问题很多，正在调试 
//17:38  前五个样例都能跑出来，但是4、5跑了一秒多（预估32pts) 
//17:54  优化了一下输入输出，算了一下复杂度，加上CCF的评测机应该比这个电脑好，其实应该是能过前15个点的（预估60pts) 
//18:00  对于建图部分还是没有什么想法......时间不多了啊 
//18:18  因为发题晚了老师给延了十分钟 
