#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e6 + 5;
const int INF = 0x3f3f3f3f;

int c,T;
int n;
ll d;
ll p[N];
ll diff = 0;
ll ans = 0;
ll cnt = 0;
ll minn = LLONG_MAX;

void dfs(int u,int e,int step){
	if(u == e){
		if(step < minn){
			minn = step;
			cnt = 1;
		}
		else cnt++;
	}
	
	for(int i=u+1;i<=e;i++){
		if(p[i] - p[u] <= d) dfs(i,e,step+1);
		else break;
	}
}

void solve(){
	ans = 0;
	
	cin >> n >> d;
	for(int i=1;i<=n;i++){
		cin >> p[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			cnt = 0;
			minn = LLONG_MAX;
			
			dfs(i,j,0);
			
			if(cnt == 2) ans++;
		}
	}
	
	cout << ans << '\n';
}

void solveA(){
	cin >> n >> d;
	for(int i=1;i<=n;i++){
		cin >> p[i];
	}
	
	diff = p[2] - p[1];
	
	if(d <= diff) cout << 0 << '\n';
	else if(d % diff != 0) cout << max(n - d / diff - 1,(ll)0) << '\n';
	else if(d % diff == 0) cout << max(n - d / diff - 2,(ll)0) << '\n';
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> T;
	while(T--){
		if(c == 11 || c == 12) solveA();
		else solve();
	}
	
	return 0;
}
