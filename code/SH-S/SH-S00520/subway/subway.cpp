#include<bits/stdc++.h>//出题人在什么样的啥子心态下出的这么恶心的题目?? 15:17 pass
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i = a;i <= b;++i)
#define per(i,a,b) for(int i = b;i >= a;--i)
inline ll read(){
	ll x = 0,f = 1;
	char c = getchar();
	while(('0' > c || c > '9') && c != '-')c = getchar();
	if(c == '-')f = -1,c = getchar();
	while('0' <= c && c <= '9')x = x * 10 + c - 48,c = getchar();
	return x * f;
}
#define N 508
#define M 500005
ll c,n,m,d,q,u,v,tz[M],sz[N],ds[N][N];//tz：地铁口到达站厅 
vector<pair<ll,ll> > dz[M]; // i号站厅到first号地铁线路，耗时second
vector<pair<ll,ll> > tc[N]; // i号列车，到站厅first 耗时second 
vector<pair<ll,ll> > ed[N]; // i号列车，换乘first号列车，耗时最短second （编号n+1,n+2是起始站厅和终点站厅 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c = read(),n = read(),m = read(),d = read(),q = read();
	rep(i,1,m)tz[i] = read();
	rep(i,1,n){
		sz[i] = read();
		rep(j,1,sz[i]){
			ll a = read(),t = read();
			dz[a].push_back(make_pair(i,t));
			tc[i].push_back(make_pair(a,t)); 
		}
		sort(tc[i].begin(),tc[i].end());
	}
	rep(i,1,n)rep(j,1,n)ds[i][j] = 1e18;
	rep(i,1,n)ds[i][i] = 0;
	rep(i,1,m){
		ll Sz = dz[i].size();
		rep(j,0,Sz - 1){
			rep(J,j + 1,Sz - 1){
				ll U = dz[i][j].first,V = dz[i][J].first,UW = dz[i][j].second,VW = dz[i][J].second;
				ds[U][V] = min(ds[U][V],UW + VW);
				ds[V][U] = ds[U][V]; 
			}
		}
	}
	rep(k,1,n){
		rep(i,1,n){
			rep(j,1,n){
				ds[i][j] = min(ds[i][j],ds[i][k] + ds[k][j]);
			}
		}
	}
	while(q--){
		u = read(),v = read();
		ll res = 1e18;
		for(auto T : dz[u]){
			ll V = T.first,W = T.second;
			for(auto R : dz[v]){
				ll VR = R.first,WR = R.second;
				res = min(res,ds[V][VR] + W + WR);
			}
		}
		printf("%lld\n",res + tz[u] + tz[v]);
	} 
	return 0;
}
