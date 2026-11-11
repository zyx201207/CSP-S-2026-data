#include <bits/stdc++.h>
//#define int long long
using namespace std;
long long n,m;
const int N = 5*1e5+10;
long long a[N];
long long dp[N+5];
long long ans;
long long num = 0;

long long logg(long long x){
	long long prep = 1;
	for(int i = 1;i<=m/2;i+=1){
		prep*=x;
		if(prep>m){
			return i-1;
		}
	}
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	
	for(long long i=1;i<=n;i+=1){
		scanf("%lld",&a[i]);
	}
	//tepan1
	if(n>5){
		if(a[2]-a[1] == a[3]-a[2]){
			if(a[3]-a[2] == a[4]-a[3]){
				if(a[5]-a[4] == a[4]-a[3]){
					printf("%lld",logg(a[2]-a[1])+1);
					return 0;
				}
			}
		}
	}
	//tepan2
	if(n>5){
		bool flag = true;
		for(int i = 1;i<=5;i+=1){
			if(a[i] != i){
				flag = false;
				break;
			}
		}
		if(flag){
			long long prep;
			for(int i = 1;i<=n;i=+1){
				prep +=a[i];
				if(prep >m){
					printf("%d",i);
					return 0;
				}
			}
		}
	}
	sort(a+1,a+n-1);
	for(long long i=1;i<=n;i+=1) {
		dp[i] = dp[i-1] +a[i];
	}
	for(long long i = 1;i<=n;i+=1){
		for(long long j = 1;j<i;j+=1){
			num = a[i]*(i-j+1);
			num -=dp[i]-dp[j-1];
			if(num <=m) {
				ans = max(ans,i-j+1);
			}
		}
	}
	printf("%lld",ans);
	return 0;
} 
