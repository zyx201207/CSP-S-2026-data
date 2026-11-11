#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = LLONG_MAX;

#define nc() ((p1==p2 && (p2=(p1=buf)+fread(buf, 1, N, stdin))), p1==p2 ? EOF : *p1++)
namespace FIO{
	const int N = 1<<20;
	char buf[N], *p1 = buf, *p2 = buf;
	inline ll read(){
		int x = 0, f = 1;
		char c = nc();
		for(;!isdigit(c);c=nc())if(c=='-')f=-1;
		for(;isdigit(c);c=nc())x = x*10+(c^48);
		return f * x;
	}
}
#define rd FIO::read()

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out","w",stdout);
	
	
	ll n = rd, m = rd;
	
	vector<int>arr(n+1, 0);
	for(int i=1;i<=n;i++)arr[i] = rd;
	sort(arr.begin(), arr.end());
	
	vector<ll>diff(n+1, 0);
	for(int i=1;i<=n;i++)diff[i] = arr.back() - arr[i];
	
	vector<ll>backsum(n+1, 0);
	for(int i=2;i<=n;i++)backsum[i] = backsum[i-1] + diff[n-i+1];

	
//	for( int i = 0; i<=n;i++)cout << arr[i] << ' ';
//	cout << '\n';
//	for( int i = 0; i<=n;i++)cout << diff[i] << ' ';
//	cout << '\n';
//	for( int i = 0; i<=n;i++)cout << backsum[i] << ' ';
//	cout << '\n';

	

	
	auto check = [&](ll x) -> bool{
		ll need = INF;
		
		for(int i=1,j=x;j<=n;i++,j++){
			ll t = backsum[j] - backsum[i-1] - x*diff[n-i+1];
			//cout << x <<':' <<t<<' '<<j<<' '<<i<<'\n';
			need = min(need, t);
		}
		return need <= m;
	};
	
	
	ll l = 1, r = n+1;	
	
	while(l<r){
		ll mid = (l+r) >> 1;
		if(check(mid)) l = mid + 1;
		else r = mid;
	}
	
	cout << l - 1 << '\n';
	
	return 0;
}
