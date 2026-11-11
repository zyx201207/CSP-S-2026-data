#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(false) , std::cin.tie(0) , std::cout.tie(0);
#define fi first
#define se second
#define pb push_back

using pii = std::pair <int , int>;
using i64 = long long;
using u64 = unsigned long long;

using namespace std;

const int MAXN = 5e5 + 10;
int n , ans;
i64 m , tot;

i64 a[MAXN] , pre[MAXN];

int main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);

	fastio;
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	sort(a + 1 , a + 1 + n);

	for(int i = 1 ; i <= n ; i++) pre[i] = pre[i - 1] + a[i];

	ans = 0;
	for(int i = 1 ; i <= n ; i++){
		int l = 1 , r = i , mid;
		while(l < r){
			mid = (l + r) >> 1;
			if(1ll * (i - mid + 1) * a[i] <= m + (pre[i] - pre[mid - 1])) r = mid;
			else l = mid + 1;
		}

		ans = max(ans , i - l + 1);
	}

	cout << ans;
	return 0;
}
/*
g++ crystal.cpp -o crystal -O2 -std=c++14 -static
./crystal
*/