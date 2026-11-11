#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void FileIO(const char * inf, const char * ouf) {
	freopen(inf, "r", stdin);
	freopen(ouf, "w", stdout);
}

constexpr int MAXN = 500010;

int n, m, c;
int d, q;
ll w[MAXN];
int lsc[510];
pair<int, ll> sta[MAXN][32];
int stalcnt[MAXN];
ll mwil[510][510]; 

void Floyd() {
	for (int k=1;k<=n;k++) {
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) {
				mwil[i][j] = min(mwil[i][j], mwil[i][k] + mwil[k][j]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	FileIO("subway.in", "subway.out");
	cin >> c >> n >> m >> d >> q;
	for (int i=1;i<=m;i++) cin>>w[i];
	for (int i=1;i<=n;i++) {
		cin>>lsc[i];
		int staid;
		ll walktime;
		for (int j=1;j<=lsc[i];j++) {
			cin>>staid>>walktime;
			// lines[i].push_back({staid, walktime});
			sta[staid][++stalcnt[staid]]={i, walktime};
		}
	}
//	ll SM1 = 0, SM2 = 0;
//	for (int i=1;i<=n;i++) SM1 += lsc[i];
//	for (int i=1;i<=m;i++) SM2 += stalcnt[i];
	// assert(SM1 == SM2);
	// 初始化换乘步行时长 
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			mwil[i][j] = (1ll<<60);
		}
	}
	// clog<<"Time: "<<1.0*clock()/CLOCKS_PER_SEC<<"s"<<endl;
	// 给换乘线路连边 
	for (int i=1;i<=n;i++) mwil[i][i] = 0;
	// int cnt=0;
	for (int i=1;i<=m;i++) {
		int sz = stalcnt[i];
		for (int j1=1;j1<=sz;j1++) {
			for (int j2=j1+1;j2<=sz;j2++) {
				// cnt++;
				mwil[sta[i][j1].first][sta[i][j2].first] = min(mwil[sta[i][j1].first][sta[i][j2].first], sta[i][j1].second + sta[i][j2].second);
				mwil[sta[i][j2].first][sta[i][j1].first] = min(mwil[sta[i][j2].first][sta[i][j1].first], sta[i][j2].second + sta[i][j1].second);
			}
		}
	}
	// clog<<n<<" "<<cnt<<endl;
	// clog<<"Time: "<<1.0*clock()/CLOCKS_PER_SEC<<"s"<<endl;
	// 求所有线路两两之间的最小步行时长 
	Floyd();
	// clog<<"Time: "<<1.0*clock()/CLOCKS_PER_SEC<<"s"<<endl;
	
	for (int qc=1;qc<=q;qc++) {
		int u, v;
		cin>>u>>v;
		ll ans = 1ll<<60;
		// 从哪条线路开始 
		for (int ii = 1; ii <= stalcnt[u]; ii++) {
			auto i = sta[u][ii];
			// 在哪条线路结束
			for (int jj = 1; jj <= stalcnt[v]; jj++) {
				auto j = sta[v][jj];
				ans = min(ans, i.second + j.second + mwil[i.first][j.first]);
			} 
		}
		
		cout<<w[u]+w[v]+ans<<endl; // 不要忘了加上进站出站时间 
	}
	
	// clog<<"Time: "<<1.0*clock()/CLOCKS_PER_SEC<<"s"<<endl;
	return 0;
}
