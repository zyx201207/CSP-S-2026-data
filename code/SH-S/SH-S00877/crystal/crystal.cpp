#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long n, m;
long long a[500005], sum[500005];
bool check(long long tar){
	for(int i = tar; i <= n; i++){
		if(a[i]*tar-sum[i]+sum[i-tar]<=m)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)cin >> a[i];
	sort(a+1, a+n+1);
	for(int i = 1; i <= n; i++)sum[i] = a[i]+sum[i-1];
	long long l = 1, r = n;
	while(l<r){
		long long mid = (l+r+1)>>1;
		if(check(mid)){
			l = mid;
		}else r = mid-1;
	}
	cout << l << endl;
	return 0;
}
