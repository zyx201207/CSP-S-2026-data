#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
int n;//2e5
const int N = 2e5+5;
struct Node {
	ll a;
	char c;
};
vector<Node> s, t;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	cin>>n;
	s.resize(n+2);
	t.resize(n+2);
	for(int i=1;i<=n;i++) {
		cin>>s[i].a>>s[i].c;
		t[n+1-i] = s[i];
	}
	ll sx, sy, tx, ty, ans;
	sx=tx=sy=ty=1, ans=0;
	while(sx<=n && sy<=n) {
		ll len=min(s[sx].a-sy+1, t[tx].a-ty+1);
		ans += (s[sx].c!=t[tx].c)*len;
		sy+=len, ty+=len;
		if(sy>s[sx].a) sx++, sy=1;
		if(ty>t[tx].a) tx++, ty=1;
		//printf("%lld %lld %lld %lld %lld\n", sx, sy, tx, ty, ans);
	}
	cout<<((ans+1)/2)<<'\n';
    return 0;
}
