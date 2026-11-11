#include <bits/stdc++.h>
using namespace std;
long long a[1000007],s[1000007];
long long n,m;
bool check(long long k){
	for(int i=k;i<=n;i++){
		if(k*a[i]-(s[i]-s[i-k])<=m){
			return 1;
		}
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	long long l=1,r=n,ans;
	while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	cout << ans;
} 
