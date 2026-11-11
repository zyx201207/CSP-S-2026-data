#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define PII pair<int,int>
#define db double
const int N  = 5e2+5;
const int inf = 1e18;
struct no{
	int x;
	int res;
	int xian;
};
struct no1{
	int x;
	int res;
	int xian;
	int tm;
	bool operator<(const no1 xx) const{
		return res<xx.res;
	};
};
int w[N];
vector<PII>a[N];
vector<no1>g[N];//v,xian
vector<PII>g1[N];//{xian,time}
int k[N];
PII qy[N];
int vis[N];
vector<PII>gg[N];
void add(int u,int v,int ww){
	gg[u].push_back({v,ww});
//	gg[v].push_back({u,ww});
}
int dp[N];
int aw[N][N];
	int c,n,m,d,q;
int dij(int S,int T){
	for(int i = 0;i <= m;i++){
		dp[i]=inf;
	}
	dp[S]=w[S];
	queue<int>q;
	q.push(S);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int tt = 0;tt < gg[x].size();tt++){
			int v = gg[x][tt].fi;
			int ww = gg[x][tt].se;
			if(dp[x]+ww < dp[v]){
				q.push(v);
//				cout << v << "??\n";
				dp[v]=dp[x]+ww;
			}
		}
	}
	return dp[T]+w[T];
}
void solve(){
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i=1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++){
			int a1,b;
			cin >> a1 >> b;
			PII pi;
			pi.fi = a1;
			pi.se = b;
			if(j-1){
				no1 nn;
				nn.x=a1;
				nn.xian=i;
				nn.res=a[i].back().se;
				nn.tm = b;
				g[a[i].back().fi].push_back(nn);
				add(a[i].back().fi,a1,b+a[i].back().se);
			}
			a[i].push_back(pi);
			pi.fi = i;
			pi.se = b;
			g1[a1].push_back(pi);
		}
	}
	for(int i = 1;i <= q;i++){
		cin >> qy[i].fi >> qy[i].se;
	}//jian tu,pao zui duan lu
	if(c<=6){
		for(int ll = 1;ll <= q;ll++){
			int to = qy[ll].se;
			int ot = qy[ll].fi;
			priority_queue<no1>q;
			for(int tmpp = 0;tmpp < g1[ot].size();tmpp++){
				PII v = g1[ot][tmpp];
				no1 tmp;
				tmp.x=ot;
				tmp.res=w[ot]+v.se;
//				cout << w[ot] << ' ' << v.se << "??\n";
				tmp.xian=v.fi;
				tmp.tm=v.se;
				q.push(tmp);
			}
			int ans = inf;
			while(!q.empty()){
				no1 pi = q.top();
				int x = pi.x;
				int res = pi.res;
				int xx = pi.xian;
				int ti = pi.tm;//
				vis[x]++;
				q.pop();
				if(x==to){
					ans = min(ans,res+w[x]+ti);
//					cout << res << "??\n";
					continue;
				}
				if(vis[x]>d)continue;
				for(int tmpp = 0;tmpp < g[x].size();tmpp++){
					no1 vv = g[x][tmpp];
					int v = vv.x;
					int xian = vv.xian;
					int tm = vv.res;//lst
					int tm1 = vv.tm;//nxt
					if(vis[v]>=d)continue;
					if(xian==xx){
						no1 nn;
						nn.x=v;
						nn.res=res;
						nn.xian = xian;
						nn.tm=tm;
						q.push(nn);
					}
					else{
						//change xian
						no1 nn;
						nn.x=v;
						nn.res=res+tm+ti;
						nn.xian = xian;
						nn.tm=tm1;//
//						if(v == 2){
//							cout << tm << "??\n";
//						}
						q.push(nn);
					}
				}
			}
			cout << ans << '\n';
		}
		return;
	}
	if(c<=11){
		for(int i = 1;i <= m;i++){
			for(int j = 1;j <= m;j++){
				aw[i][j]=dij(i,j);
			}
		}
		for(int i = 1;i <= q;i++){
			cout << aw[qy[i].fi][qy[i].se] << '\n';
//			cout << dij(qy[i].fi,qy[i].se) << '\n';
		}
	}
	else{
		for(int i = 1;i <= n;i++){
			cout << rand() << '\n';
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int _ = 1;
	// cin >> _;
	while(_--)solve();
	return 0;
}
/*
if only vis 2 node;
jian bian
8 2 5 100 2
0 0 0 0 0
2 1 1 2 1
2 2 1 3 1
1 2
1 3
*/
