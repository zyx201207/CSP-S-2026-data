#include <bits/stdc++.h>

using namespace std;

#define int long long 

constexpr int N = 5e5 + 5;
int ans = 0,n,a[N],m,s[N];

inline bool check(int l,int r){
	int cost = a[r] * (r - l + 1) - (s[r] - s[l - 1]);
	if(cost <= m) return true;
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::cin >> n >> m;
	for(int i = 1; i <= n; ++ i){
		std::cin >> a[i];
	}
	std::sort(a + 1,a + n + 1);
	for(int i = 1; i <= n; ++ i){
		s[i] = s[i - 1] + a[i];
	}
	int l = 1;
	// l 是最左边可行的答案
	for(int i = 1; i <= n; ++ i){
		while(l < i && (!check(l,i))) ++ l;
		ans = std::max(ans,i - l + 1ll);
	} 
	std::cout << ans;
	return 0;
} 
