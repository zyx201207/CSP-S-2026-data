#include<bits/stdc++.h>
using namespace std;
long long n, m, a[100010], ans = 0, s[5020];int dp[5050][5050];
int solver(int k){
	int sum = 0;
	for(long long i = 0;i <= n; i++){
		sum += abs(dp[k][i]);
	}
	return sum;
}
bool cmp(int a,int b){
	return abs(a) < abs(b);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	cin>>n>>m;
	for(long long i = 1 ;i <= n;i++){
		cin>>a[i];
	}
	if(n <= 5000){
		for(long long i = 1 ;i <= n;i++){
			for(long long j = 1 ;j <= n;j++){
				dp[i][j] = a[i] - a[j];
			}
		}
		int mine = 1000000000,chick = 0;
		for(long long i = 1 ;i <= n;i++){
			s[i] = solver(i);
			if(mine > s[i]){
				mine = s[i];chick = i;
			}
		}
		for(long long i = 1 ;i <= n;i++){
			s[i] = dp[chick][i];
		}
		sort(s+1,s+n+1,cmp);
		int i = 1;
		while(m > 0){
			m -= abs(s[i++]);
			if(m >= 0){
				ans++;
			}
		}
		cout<<ans;
	}else{
		long long v = abs(a[1] - a[2]);
		long long r = 0;
		if(v == 1){
			for(long long i = 1;i <= n;i++){
				long long u = ceil((a[1] + a[i]) * i / 2.0);
				if(u <= m){
					r = i;
				}else{
					cout<<r+1;
					return 0;
				}
			}
		}else{
			for(long long i = 1;i <= n;i++){
				long long u = ceil((a[1] + a[i]) * i / 2.0);
				if(u <= m){
					r = u;
				}else{
					cout<<i;
					return 0;
				}
			}
		}
	}
	return 0;
} 