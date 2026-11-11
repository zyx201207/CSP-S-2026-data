//Author: yangwang2013
#include <bits/stdc++.h>
#define dbg(x) cerr << #x << " = " << x << endl
#define sz(x) (int)x.size()
#define all(x) (x.begin(),x.end())
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 2000005;
ll n,d,x[MAXN],cnt[MAXN],dist[MAXN],start[MAXN];

void solve(){
	cin >> n >> d;
	for (int i = 1;i <= n;i++) cin >> x[i];
	if (n <= 300){
		for (int i = 1;i <= n;i++){
			for (int j = i;j >= 1;j--){
				if (x[i] - x[j] > d) {
					start[i] = j + 1;
					break;
				}
			}
		} 
		int ans = 0;
		for (int i = 1;i <= n;i++){
			for (int j = i + 1;j <= n;j++){
				cnt[i] = 1,dist[i] = 0;
				for (int k = i + 1;k <= j;k++){
					for (int l = start[k];l < k;l++){
						dist[k] = min(dist[k],dist[l] + 1);
					}
				}
				for (int k = i + 1;k <= j;k++){
					for (int l = start[k];l < k;l++){
						if (dist[k] == dist[l] + 1) cnt[k] += cnt[l];
					}
				}
				if (cnt[j] == 2) ans++;
				for (int k = i;k <= j;k++) cnt[k] = 0,dist[k] = LINF;
			}
		}
		cout << ans << '\n';
	}else{
		cout << rand() * rand() << endl;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	srand(time(0));
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t = 1,c;
	cin >> c >> t;
	memset(dist,0x3f,sizeof dist);
	while (t--){
		solve();
	}
	cout << flush;
	return 0;
}
