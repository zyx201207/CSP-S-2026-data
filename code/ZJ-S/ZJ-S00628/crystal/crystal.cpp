#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 10;

long long a[MAXN];

int n;
long long m;

long long last;
//¹«²î 

long long sum[MAXN];
//Ç°×ººÍ 

inline bool check(int x){
	long long sum;
	sum = m;
	for(int i = 1; i <= x; ++ i){
		sum -= 1LL * (x - i) * last;
		if(sum < 0){
			return 0;
		}
	}
	if(sum >= 0){
		return 1;
	}else{
		return 0;
	}
}

inline bool k(int x){
	for(int i = x; i <= n; ++ i){
		if(sum[i] - sum[i - x]>= a[i] * x - m){
			return 1;
		}
	}
	return 0;
}

int main(){
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios :: sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	
	bool flag;
	flag = 0;
	if(n > 2){
		cin >> a[1] >> a[2];
		last = a[2] - a[1];
		for(int i = 3; i <= n; ++ i){
			cin >> a[i];
			if(a[i] - a[i - 1] != last){
				flag = 1;
			}
		}
	}else if(n == 1){
		cout << 1;
		return 0;
	}else{
		cin >> a[1] >> a[2];
		long long minn;
		long long maxx;
		minn = min(a[1], a[2]);
		maxx = max(a[1], a[2]);
		
		if(minn >= maxx - m){
			cout << 2;
		}else{
			cout << 1;
		}
		return 0;
	}
	
	if(!flag){
		if(last < 0){
			last = -last;
		}
		int left, right;
		int ans;
		ans = 1;
		left = 1;
		right = n;
		while(left <= right){
			int mid;
			mid = (left + right) >> 1;
			if(check(mid)){
				ans = mid;
				left = mid + 1;
			}else{
				right = mid - 1;
			}
		}
		cout << ans;
	}else{
		sort(a + 1, a + n + 1);
		for(int i = 1; i <= n; ++ i){
			sum[i] = sum[i - 1] + a[i]; 
		}
		int left, right;
		left = 1;
		right = n;
		
		int ans;
		ans = 1;
		while(left <= right){
			int mid;
			mid = (left + right) >> 1;
			if(k(mid)){
				ans = mid;
				left = mid + 1;
			}else{
				right = mid - 1;
			}
		}
		cout << ans;
	}
	
	return 0;
} 
