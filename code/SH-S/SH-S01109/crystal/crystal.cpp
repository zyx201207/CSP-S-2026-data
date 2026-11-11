#include<bits/stdc++.h>

// 30 mins finished, is that a good omen? Not bad but also not good.
// 17:18 is it able to obtain 1= with 163pts?
// expected: 100pts

using namespace std;

long long n,m;
long long a[500010];
long long d[500010]; 
long long ds[500010];

bool Check(int x){  //
	// init 
	long long sm = 0;
	for(int i = 1; i < x; i ++){
		sm += d[i]*i;
	}
	//
	for(int i = 1; i+x-1 <= n; i ++){
		if(sm <= m && sm >= 0) return 1;
		// update
		sm += (x-1)*d[i+x-1];
		sm -= ds[i+x-2]-ds[i-1];
	}
	return 0;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	
	sort(a+1,a+n+1);
	for(int i = 1; i <= n; i ++){
		d[i] = a[i+1] - a[i];
		ds[i] = ds[i-1] + d[i];
	}
	
	long long l = 2, r = n, ans = 1;
	while(l <= r){
		int mid = l+r>>1;
		if(Check(mid))
			ans = mid, l = mid + 1;
		else
			r = mid - 1;
	}
	
	cout << ans;
	
	return 0;
}
