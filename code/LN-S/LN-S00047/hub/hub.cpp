#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = int;

using i128 = __int128;
using u128 = unsigned __int128;

#ifdef ZYX2012_DUIPAI
mt19937_64 mrand(random_device{}());
i64 rnd(i64 l,i64 r){
	return mrand() % (r - l + 1) + l;
}
#endif

void solve(){
	int n,k;
	cin >> n >> k;

	for (int i = n;--i;){
		int x,y;
		cin >> x >> y;
	}

	cout << (n == k?0:1) << '\n';
}

int main (){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	int c,T;
	cin >> c >> T;

	for (;T--;solve());
}