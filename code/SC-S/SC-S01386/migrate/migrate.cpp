#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define nc() ((p1==p2 && (p2=(p1=buf)+fread(buf, 1, N, stdin))), p1==p2 ? EOF : *p1++)
namespace FIO{
	const int N = 1<<20;
	char buf[N], *p1 = buf, *p2 = buf;
	inline int read(){
		int x = 0, f = 1;
		char c = nc();
		for(;!isdigit(c);c=nc())if(c=='-')f=-1;
		for(;isdigit(c);c=nc())x = x*10+(c^48);
		return f * x;
	}
}
#define rd FIO::read()

void dfs(int x, ll &n, ll &dis, vector<ll>&arr, vector<ll>&cnt, vector<int>&steps, int step){
	cnt[x]++;
	for(int i=x+1;i<=n;i++){
		if(arr[i] - arr[x]<= dis && steps[i]>=step+1){
			if(steps[i]>step+1)cnt[i]=0, steps[i] = step+1;
			dfs(i, n, dis, arr, cnt, steps, step+1);
		}
	}
}


void solve(){
	ll n = rd, dis = rd;
	
	vector<ll>arr(n+1, 0);
	vector<ll>cnt(n+1, 0);
	vector<int>steps(n+1, n+1);
	for(int i=1;i<=n;i++)arr[i] = rd;
	
	ll ans = 0;
	auto bakcnt = cnt;
	auto baksteps = steps;
	for(int i=1;i<n-2;i++){
		steps = baksteps;
		cnt = bakcnt;
		steps[i] = 0;
		dfs(i, n, dis, arr, cnt, steps, 0);
		for(int j=i;j<=n;j++)if(cnt[j] == 2)ans++;
	}
	
	
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out","w",stdout);
	
	int c = rd, t = rd;
	while(t--)solve();
	
	return 0;
}