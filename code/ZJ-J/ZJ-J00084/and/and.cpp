#include <bits/stdc++.h>
using namespace std;
long long a[200005],dp[200005];
bool check(long long u){
	for(int i=1;i<=31;i++){
		if(pow(2,i)-1==u){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int flagB=1,flagA=1;
	int n,m;
	long long maxn=0;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=i-1){
			flagB=0;
		}
		if(check(a[i])){
			flagA=0;
		}
		maxn = max(maxn,a[i]);
	}
	if(m==1){
		cout << maxn << endl;
	}else if(m==2){
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i) continue;
				ans = max(ans,a[i]&a[j]);
			}
		}
		cout << ans << endl;
	}else if(m==n){
		long long ans = a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout << ans << endl;
	}else{
		sort(a+1,a+n+1,greater<int>());
		long long sum=a[1];
		for(int i=2;i<=m;i++){
			sum &= a[i];
		}
		cout << sum << endl;
	}
	return 0;
}