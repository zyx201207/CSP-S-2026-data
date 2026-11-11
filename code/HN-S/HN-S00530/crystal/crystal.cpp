#include<bits/stdc++.h>
//long long
#define endl '\n'
using namespace std;

long long n,m,a[500050],ans,s[500050];

long long c(long long l,long long r,long long t){
	long long res = 0;
	while(l <= r){
		long long mid = (l + r) >> 1ll;
		if(a[t] * (t - mid + 1) - (s[t] - s[mid - 1]) <= m){
			r = mid - 1;
			res = mid;
		}else{
			l = mid + 1;
		}
	}
	return res;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(long long i = 1;i <= n;i ++){
		cin >> a[i];
	}
	sort(a + 1,a + 1 + n);
	for(long long i = 1;i <= n;i ++){
		s[i] = s[i - 1] + a[i];
		long long t = a[i] * i - s[i];
		if(m > t){
			ans = max(ans,i);
		}else{
			long long idx = c(1,i,i);
			ans = max(ans,i - idx + 1ll);
		}
	}
	cout << ans;
	return 0;
}

