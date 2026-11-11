# include <bits/stdc++.h>
using namespace std;

const int N = 5 * 1e5+5;
long long n,m;
long long a[N];
long long s[N];

inline bool check(int x){
	long long ans = 1e9,t = 0;
	for(int i = 1;i <= n-x;i++){
		t = x * a[i+x-1] - s[i+x] + s[i-1];
		ans = min(ans,t);
	}
	
	return ans <= m;
}

signed main(){
	
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	if(m == 0){
		int cnt = 1,mx = -1e9;
		for(int i = 2;i <= n;i++){
			if(a[i] == a[i-1]) cnt++;
			else	mx = max(mx,cnt),cnt = 1;
		}
		mx = max(mx,cnt);
		cout << cnt;
		return 0;
	}
	for(int i = 1;i <= n;i++){
		s[i] = s[i-1] + a[i];
	}
	
	int l = 1,r = n;
	int mid;
	while(l < r){
		mid = (l + r+1) >> 1;
		if(check(mid)) 	l = mid;
		else			r = mid-1;
	}
	
	cout << r;
	
	return 0;
} 