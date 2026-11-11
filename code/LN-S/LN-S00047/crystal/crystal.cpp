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

int main (){
	//第一题就需要结论？！
	//不能减啊，那没事了
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	int n;
	i64 m;
	cin >> n >> m;

	vector<i64> a(n + 1),c(n + 1);

	for (int i = 1;i <= n;i++) cin >> a[i];

	sort(a.begin() + 1,a.end());
	for (int i = 1;i <= n;i++) c[i] = c[i - 1] + a[i];
	int ans = 0;

	for (int i = 1;i <= n;i++){
		//从i开始
		int l = i,r = n + 1;

		auto check = [&](int id){
			//[i,mid]<=a[mid],(mid,id]>=a[mid]
			return a[id] * (id - i + 1) - c[id] + c[i - 1] <= m;
		};

		for (;l + 1 < r;){
			int mid = l + r >> 1;
			(check(mid)?l:r) = mid;
		}

		ans = max(ans,l - i + 1);
	}

	cout << ans << '\n';
}