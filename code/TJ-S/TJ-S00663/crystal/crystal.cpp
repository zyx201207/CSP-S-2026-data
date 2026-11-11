#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5+10;
const long long INF = 1e18;
long long a[MAXN];
long long pf[MAXN];
long long n, m;

bool check(long long x){
	long long cmin = INF;
	for(long long i = x+1; i <= n; i++){
		cmin = min(cmin, x*a[i] - (pf[i-1] - pf[i-x-1]));
	}
	return (cmin <= m);
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	bool fd = true;
	long long d;
	for(int i = 1; i <= 2; i++){
		cin >> a[i];
		if(i == 2)
			d = a[2] - a[1];
	}
	for(int i = 3; i <= n; i++){
		cin >> a[i];
		if(a[i] - a[i-1] != d)
			fd = false;
	}
	
	if(fd){
		if(m == 0){
			cout << 1;
			return 0;
		} 
		long long l = 1, r = n, mid; // 二分 x 的值 
		while(l <= r){
			mid = l + (r-l)/2;
			if(2*m >= d*mid + d*mid*mid) l = mid+1;
			else r = mid-1;
		}
		//  ans = l-1+1
		cout << l;
		return 0;
	}
	
	sort(a+1, a+n+1); // erfen  n  de zhi
	pf[0] = 0; 
	pf[1] = a[1];
	for(int i = 2; i <= n; i++){
		pf[i] = a[i] + pf[i-1];
	}
	
	long long l = 1, r = n-1, mid; // 二分 n 的值 补 n 个数成为 i 
		while(l <= r){
			mid = l + (r-l)/2;
			if(check(mid)) l = mid+1;
			else r = mid-1;
		}
	cout << l;
	///////////////////////////////////////////////////////////////////////////////////////////////////

	/*if(m == 0){                          //budui
		map<int, int> mp;
		for(int i = 1; i <= n; i++){
			mp[a[i]]++;
		}
		priority_queue<int> maxh;
		for(int i = 1; i <= n; i++){
			maxh.push(mp[a[i]]);
			cout << maxh.top();
		}
	}                                     //budui
	*/
	return 0;
}




// 4 3 2 4 6 8
