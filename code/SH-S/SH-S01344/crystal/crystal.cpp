#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+10;

long long n,m;
long long a[N];

long long dp[N];

void solve1(){
	sort(a+1,a+n+1);
	
	long long ans = 1;
	for(int i = 2;i <= n;i++){
		long long huafei = 0;
		long long cnt = 1;
		for(int j = i - 1;j >= 1;j--){
			long long num = a[i] - a[j];
			if(huafei + num <= m){
				cnt++;
				huafei+=num;
			}else{
				break;
			}
		}
		ans = max(ans,cnt);
	}
	cout << ans;
}

void solve2(){
	sort(a+1,a+n+1);
	dp[1] = 0;

	int idx = -1;
	int st = 1;
	long long ret = 0;
	while(st < n){
		long long ans = 1;
		dp[st] = 0;
		for(int i = st+1;i <= n;i++){
			ans = i - st;
			idx = i;
			dp[i] = dp[i-1] + (a[i] - a[i-1]) * (i - st);
			if(dp[i] > m){
//				cout << ans <<" " << i << endl;
				
				break;
			}
		}
		
		if(idx == n and dp[idx] < m){
			long long cnt = 1;
			long long huafei = 0;
			for(int i = idx;i >= 1;i--){
				if(huafei + a[idx] - a[i] <= m){
					huafei+= a[idx] - a[i];
					cnt++;
				}else{
					break;
				}
			}
				st = idx;

				ret =max(ret,max(cnt,ans));	
		}else{
			long long cnt = 1;
			long long huafei = 0;
			for(int i = idx-1;i >= 1;i--){
				if(huafei + a[idx] - a[i] <= m){
					huafei+= a[idx] - a[i];
					cnt++;
				}else{
					break;
				}
			}
			st = idx;
	
			ret =max(ret,max(cnt,ans));
		}
		
	}
//	for(int i= 1;i <= n;i++){
//		cout << dp[i] << " ";
//	}
//	cout << endl;
	cout << ret;
}


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	
	if(n <= 5000){
		solve1();
	}else{
		solve2();
	}
	return 0;
} 
