#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#define int long long
#define F(i, n, m) for(int i = n; i <= m; i++)
#define dF(i, n, m) for(int i = n; i >= m; i--)
using namespace std;
using ll = long long;
using ull = unsigned long long;

int const N = 5e5 + 5;
int a[N], n, m;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
//	freopen("crystal4.in", "r", stdin);
	
	cin >> n >> m;
	F(i, 1, n) {
		cin >> a[i];
	}
	sort(a+1, a+1+n);
	
	
	int head = 1, tail = 1;
	int e = m, ans = 0;
	while(e >= (a[tail+1] - a[tail]) * (tail - head+1) && tail < n) {
//		cout << head << ' ' << tail << ' ' << e  << ' ' << (a[tail+1] - a[tail]) * (tail - head+1) << '\n' ;
		e -= (a[tail+1] - a[tail]) * (tail - head+1);
		tail++;
	}
//	cout << head << ' ' << tail << ' ' << e  << ' ' << (a[tail+1] - a[tail]) * (tail - head+1) << '\n' ;
	ans = max(ans, tail - head + 1);
	while(tail < n && head <= tail) {
		while(e < (a[tail+1] - a[tail]) * (tail - head+1)) {
			e += (a[tail] - a[head]);
			head++;
//			if(head == 2)cout << head << ' ' << tail << ' ' << e  << ' ' << (a[tail+1] - a[tail]) * (tail - head+1) << '\n' ;
		}
//		cout << head << ' ' << tail << ' ' << e  << ' ' << (a[tail+1] - a[tail]) * (tail - head+1) << '\n' ;
//		break;
		while(e >= (a[tail+1] - a[tail]) * (tail - head+1) && tail < n) {
			e -= (a[tail+1] - a[tail]) * (tail - head+1);
			tail++;
		}
//		cout << head << ' ' << tail << ' ' << e  << ' ' << (a[tail+1] - a[tail]) * (tail - head+1) << '\n' ;
		ans = max(ans, tail - head+1);
	}
	cout << ans;
	return 0;
}