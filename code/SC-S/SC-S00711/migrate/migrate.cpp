#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(false) , std::cin.tie(0) , std::cout.tie(0);
#define fi first
#define se second
#define pb push_back

using pii = std::pair <int , int>;
using i64 = long long;
using u64 = unsigned long long;

using namespace std;

const int MAXN = 2e6 + 10;

int cid , TCNT;
int n;
i64 ans , d , pos[MAXN] , lcnt[MAXN] , rcnt[MAXN];

int getnxt(int now){
	if(now == n) return -1;
	if(pos[now + 1] - pos[now] > d) return now;

	int l = now + 1 , r = n , mid;
	while(l < r){
		mid = (l + r + 1) >> 1;
		if(pos[mid] - pos[now] <= d) l = mid;
		else r = mid - 1;
	}
	return l;
}
int getpre(int now){
	if(now == 1) return -1;
	if(pos[now] - pos[now - 1] > d) return now;

	int l = 1 , r = now - 1 , mid;
	while(l < r){
		mid = (l + r) >> 1;
		if(pos[now] - pos[mid] <= d) r = mid;
		else l = mid + 1;
	}
	return l;
}

namespace brute{
	pii dp[MAXN];

	void solve(){
		i64 ans = 0;
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= n ; j++) dp[j] = {0 , 0};
			dp[i] = {0 , 1};
			for(int j = i + 1 ; j <= n ; j++){
				int minval = n + 1;
				for(int t = i ; t < j ; t++) if(pos[j] - pos[t] <= d) minval = min(minval , dp[t].fi + 1);
				for(int t = i ; t < j ; t++) if(pos[j] - pos[t] <= d && dp[t].fi + 1 == minval) dp[j].se += dp[t].se;
				dp[j].fi = minval;
				ans += (dp[j].se == 2);
				// cerr << i << ' ' << j << ' ' << dp[j].fi << ' ' << dp[j].se << '\n';
			}
		}
		cout << ans << '\n';
		return;
	}
}

void solve(){
	cin >> n >> d;
	for(int i = 1 ; i <= n ; i++) cin >> pos[i] , lcnt[i] = rcnt[i] = 0;

	if(n <= 300){
		brute::solve();
		return;
	}
	
	rcnt[n] = 1;
	for(int i = n - 1 ; i >= 1 ; i--){
		int pos1 = getnxt(i);
		if(pos1 == n){
			rcnt[i] = n - i + 1;
			continue;
		}
		if(i + 1 == pos1){
			rcnt[i] = rcnt[i + 1] + 1;
			continue;
		}
		
		int pos2 = getnxt(pos1) , tpos = getnxt(pos1 - 1);
		if(tpos == pos2){
			rcnt[i] = pos1 - i + 1;
			continue;
		}
		rcnt[i] = rcnt[pos1] + (pos1 - i) - (tpos - pos1);
	}

	for(int i = 1 ; i < n ; i++){
		lcnt[i]++;
		
		int nxt = getnxt(i);
		if(nxt == i) continue;

		lcnt[nxt] += lcnt[i];
	}
	lcnt[n]++;

	ans = 0;
	for(int i = 1 ; i <= n - 3 ; i++){
		int pos1 = getnxt(i);
		if(pos1 == n || pos1 == i + 1) continue;
		int pos2 = getnxt(pos1) , tpos = getnxt(pos1 - 1);
		
		if(pos1 == pos2 || tpos == pos1) continue;

		i64 tmpans = ans;
		if(tpos == pos2 && (pos1 - 1 == i + 1 || getnxt(pos1 - 2) != pos2)){
			int tmp = 0;
			if(pos2 - 1 == pos1) tmp = 0;
			else tmp = getnxt(pos2 - 1) - pos2;

			int tlcnt = lcnt[i];
			if(i > 1 && getnxt(i - 1) >= pos1 - 1) tlcnt = 1;
			
			if(pos2 - 1 != pos1 && getnxt(pos2 - 1) == getnxt(pos2)) ans += tlcnt;
			else ans += tlcnt * (rcnt[pos2] - tmp);
			
			if(getnxt(i) != i) lcnt[getnxt(i)] -= lcnt[i];
			// cerr << i << ' ' << pos2 << ' ' << ans - tmpans << '\n';
		}

		int l = pos1 + 1 , r = min(tpos , pos2 - 1);
		if(pos1 - 1 != i + 1) l = max(l , getnxt(pos1 - 2) + 1);

		int tlcnt = lcnt[i];
		if(i > 1 && getnxt(i - 1) >= pos1 - 1) tlcnt = 1;
		ans += tlcnt * max(0 , r - l + 1);
	}

	cout << ans << '\n';
	return;
}

int main(){
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	fastio;
	cin >> cid >> TCNT;
	while(TCNT--) solve();
	return 0;
}
/*
g++ migrate.cpp -o migrate -O2 -std=c++14 -static
./migrate
diff -Z test.out migrate3.ans

15:49锛?
鎯充簡涓€涓劅瑙夋槸瀵瑰畬浜嗙殑鍏呰鏉′欢锛屽啓涓€鍙戠湅鐪嬪涓嶅
16:12锛?
鐜板湪鐨勯毦鐐瑰湪浜庢€庝箞蹇€熸壘鍒颁竴涓偣鍚庨潰鍒板簳鏈夊灏戜釜鐐瑰埌瀹冪殑璺緞鍞竴锛?
鎰熻浼氫簡锛?

0 1
6 4
-3 0 1 2 3 4

ans:3

0 1
5 3
-3 0 2 3 4

ans:2

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

ans:6

0 1
10 333333333333333327
-1000000000000000000 -666666666666666673 -333333333333333346 -111111111111111128 111111111111111090 222222222222222199 333333333333333308 444444444444444417 666666666666666635 999999999999999962

1 7
1 8
2 7
2 8
3 7
3 8
4 7
4 8
5 9
5 10
6 9
6 10

ans:12

0 1
10 22
0 7 14 21 28 35 42 49 56 63

ans:5
*/