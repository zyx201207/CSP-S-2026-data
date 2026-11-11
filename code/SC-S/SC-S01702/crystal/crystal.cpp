#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

namespace fio{
	constexpr int S = 1 << 20;
	char buf[S];
	size_t idx, sz;
	int gc(){
		if(idx == sz){
			sz = fread(buf, 1, S, stdin);
			idx = 0;
			if(!sz)
				return EOF;
		}
		return buf[idx++];
	}
	template <typename T>
	bool read(T& x){
		x = 0;
		T f = 1;
		int c = gc();
		while(c != EOF && (c < '0' || c > '9')){
			if(c == '-')
				f = -1;
			c = gc();
		}
		if(c == EOF)
			return false;
		while(c >= '0' && c <= '9'){
			x = x * 10 + (c ^ 48);
			c = gc();
		}
		x *= f;
		return true;
	}
	template <typename T, typename... Args>
	bool read(T& x, Args&... args){
		return read(x) && read(args...);
	}
}

int main(){
//	freopen("temp.in", "r", stdin);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	ll m;
	fio::read(n, m);
	vector <int> a(n + 1);
	for(int i = 1; i <= n; ++i)
		fio::read(a[i]);
	sort(a.begin() + 1, a.end());
	int ans = 1;
	vector <ll> pre(n + 1);
	int l = 1;
	for(int i = 1; i <= n; ++i){
		pre[i] = pre[i - 1] + a[i];
		while((i - l + 1ll) * a[i] - (pre[i] - pre[l - 1]) > m)
			++l;
		ans = max(ans, i - l + 1);
	}
	cout << ans << '\n';
	return 0;
}