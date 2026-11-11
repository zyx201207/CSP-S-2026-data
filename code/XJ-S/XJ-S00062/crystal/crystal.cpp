#include <bits/stdc++.h>
using namespace std;
const int N = 500010; 
long long n,m,ans;
long long a[N],cha[N];
bool check(long long x)
{
	for(long long k = x;k <= n;k++){
		long long cnt = 0,sum = 0;
		for(long long i = k-x+1;i < k;i++){
			cnt++;
			sum += cnt * cha[i];
		}
		if(sum <= m)return true;
	}
	return false;
}
bool check1(long long x)
{
	for(long long k = x;k <= n;k++){
		long long sum;
		sum = (x-1)*(x-2)/2;
		if(sum <= m)return true;
	}
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	if(m > 1000000999){
		long long l = 1,r = n;
		while(l <= r){
			long long mid = (l+r)>>1;
			if(check1(mid)){
				ans = mid;
				l = mid+1;
			}else{
				r = mid-1;
			}
		}
		cout << ans;
		return 0;
	}
	for(int i = 2;i <= n;i++){
		cha[i] = a[i]-a[i-1];
	}
	long long l = 1,r = n;
	while(l <= r){
		long long mid = (l+r)>>1;
		if(check(mid)){
			ans = mid;
			l = mid+1;
		}else{
			r = mid-1;
		}
	}
	cout << ans;
	return 0;
} 
