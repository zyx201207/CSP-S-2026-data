#include<bits/stdc++.h>
using namespace std;
long long a[500005],q[500005];
long long n,m,cnt = 0,ans = 0;
bool chA(){
	for(long long i = 1;i <= n;i ++){
		if(a[i] != i) return 0;
	}
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(long long i = 1;i <= n;i ++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i = 1;i < n;i ++) cnt += a[i+1] - a[i];
	for(long long i = 1;i <= n;i ++) q[i] = q[i-1] + a[i];
	if(chA()){
		m += m;
		for(long long i = 1;;i ++){
			if(m < i*(i - 1)){
				ans = i - 1;
				break;
			}
		}
		cout<<min(ans,n);
		return 0;
	}
	else if(n <= 5000){
		for(long long i = 1;i <= n;i ++){
			for(long long j = i;j <= n;j ++){
				long long y = 0;
				for(long long k = i;k <= j;k ++)
					y = a[j] - a[i];
				if(y <= m) ans = max(ans,j-i+1);
			}
		}
		cout<<ans;
		return 0;
	}
	long long l = 1,r = n;
	while(l <= r){
		if(cnt <= m) break;
		long long x = q[r] - q[l] - (r-l) * a[l],y = (r-l) * a[r] - q[r-1] + q[l-1];
		ans ++;
		if(x <= y){
			cnt -= y;
			r --;
		}else{
			cnt -= x;
			l ++;
		}
	}
	if(l > r){
		cout<<0;
		return 0;
	}else cout<<n-ans;
	return 0;
}

