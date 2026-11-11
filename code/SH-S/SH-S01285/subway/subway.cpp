// Think TWICE
// Code ONCE
// NEVER FORGET YOUR 143pts IN NOIP 2025

/*
首先就是，我从地铁口前往站台时间可以是固定的，不考虑就行，直接加上。 
变成直接算站厅->站厅时间。
图论？按照地铁站当节点建图？
从站厅->站台->目标站台->目标站厅
k<=5e5，不能暴力建图。
会不会是dp
dp[i][j]表示从线路i出发到线路j的最小代价
要加上它们的公共站台那里，从一个站台->站厅->站台的代价。
最后答案还有初始站台的下站厅和最终站台的上站厅。
可以枚举线路进行转移了，真棒！
还有个问题，两条线路可以有不止一个公共站台啊？
让我想想看。一个站台d<=20，最多被20个线路穿过。
转移代价最大就是d^2=400级别？（适用于直接转移？） 
真正转移时候
i j 中间线路 k
i j 直接走公共站台转移
枚举中间站台 k，走 i->k k->j
我看看。
类似floyd吧？ 
等一下，q怎么这么大
比如一个站点，我可以从多条线路进去，多条线路出来。
咋处理。
哦，还可以直接qd^2
O(md^2+n^3+qd^2) 
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define up(l,r,i) for(int i=(l);i<=(int)(r);++i)
#define pb emplace_back

void file(string fl){
	freopen((fl+".in").c_str(),"r",stdin);
	freopen((fl+".out").c_str(),"w",stdout);
}

ll ksm(ll a,ll b,ll p){
	ll ret=1%p;
	while(b){
		if(b&1)ret=ret*a%p;
		a=a*a%p;
	}
	return ret;
}

constexpr int N=507,M=5e5+7;
constexpr ll INF=1e18;

ll c,n,m,d,q,w[M],k[N],dp[N][N];
//vector<ll> a[N],t[N];
vector<pair<int,ll> > station[M];

int main(){
	file("subway");
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T=1;
	//cin>>T;
	while(T--){
		cin>>c>>n>>m>>d>>q;
		up(1,m,i)cin>>w[i];//下到站厅的时间
		up(1,n,i){
			cin>>k[i];
			up(1,k[i],j){
				ll x,y;cin>>x>>y;
//				a[j].pb(x);
//				t[j].pb(y);
				station[x].pb(make_pair(i,y));
			}
		}
		up(1,n,i)up(1,n,j)if(i!=j)dp[i][j]=INF;
		//先处理直接联通？
		up(1,m,i){
			//每个地铁站
			for(int j=0,x;j<(int)station[i].size();++j){
				x=station[i][j].first;
				ll t1=station[i][j].second;
				for(int k=j+1,y;k<(int)station[i].size();++k){
					y=station[i][k].first;
					ll t2=station[i][k].second;
					dp[x][y]=min(dp[x][y],t1+t2);
					dp[y][x]=dp[x][y];
				}
			}
		}
		//再跑类floyd 
		up(1,n,k){
			up(1,n,i){
				up(1,n,j){
					if(i==j)continue;
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
				}
			}
		}
//		up(1,n,i)up(1,n,j)cout<<dp[i][j]<<" \n"[j==n];
// OK 
		while(q--){
			ll x,y;cin>>x>>y;
//			cout<<w[x]+w[y]+
			ll ans=INF;
			for(auto i:station[x]){
				for(auto j:station[y]){
					ans=min(ans,w[x]+w[y]+i.second+j.second+dp[i.first][j.first]);
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
/*
15:45 写好第一版code。 
15:49 所有大样例都过了，NICE
有空再对拍，最慢一个点0.49s（本机，O2）
rp++ 
*/
