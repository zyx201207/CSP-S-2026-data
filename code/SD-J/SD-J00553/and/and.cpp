#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],sum,ans;
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(pow(2,int(log2(a[i])))==a[i]) {
			sum++;
		}
		if(a[i]==a[i-1]+1&&i!=1) {
			ans++;
		}
	}
	sort(a+1,a+n+1);
	if(m==1) {
		cout<<a[n];
		return 0;
	}
	if(m==2) {
		long long k=-1;
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				k=max(k,a[i]&a[j]);	
			}
		}
		cout<<k;
		return 0;
	}
	if(m==n){
		int k=a[1];
		for(int i=2; i<=n; i++) {
			k&=a[i];
		}
		cout<<k;
		return 0; 
	}
	if(sum==n){
		cout<<a[n-m+1];
		return 0;
	}
	if(ans==n-1){
		int cnt1=a[n];
		int cn=1;
		for(int i=n;i>=1;i--){
		if(cn==m){
			break;
		}
		if(cnt1&a[i-1]>cnt1&a[i-2]){
			cnt1&=a[i-1];
			cn++;
		}else{
			cnt1&=a[i-2];
			cn++;
			i--;
		}
		
		}
		cout<<cnt1;
		return 0;
	}
	if(m==n-1){
		long long k=a[1],lll=-1;
		for(int i=2; i<=n; i++) {
			k&=a[i];
		}
		for(int i=1; i<=n; i++) {
			lll=max(lll,k|a[i]);
		}
		cout<<lll;
		return 0;
	}
	ans=-1;
	long long cnt=0;
	for(int i=n; i>=1;) {
		if((a[i]&a[i-1])>(a[i]&a[i-2])&&(a[i]&a[i-1])>(a[i-1]&a[i-2])) {
			cnt+=2;
			ans&=(a[i]&a[i-1]);
			if(cnt==m) {
				cout<<ans;
				return 0;
			}
			if(cnt==m-1) {
				for(int j=i-2; j>=1; j--) {
					ans=max(ans,ans&a[j]);
				}
				cout<<ans;
				return 0;
			}
			i--;
		}
		if((a[i]&a[i-2])>(a[i]&a[i-1])&&(a[i]&a[i-2])>(a[i-1]&a[i-2])) {
			cnt+=2;
			ans&=(a[i]&a[i-2]);
			if(cnt==m) {
				cout<<ans;
				return 0;
			}
			if(cnt==m-1) {
				for(int j=i-3; j>=1; j--) {
					ans=max(ans,ans&a[j]);
				}
				cout<<ans;
				return 0;
			}
			i-=2;
		} else {
			cnt+=2;
			ans&=(a[i-1]&a[i-2]);
			if(cnt==m) {
				cout<<ans;
				return 0;
			}
			if(cnt==m-1) {
				for(int j=i-3; j>=1; j--) {
					ans=max(ans,ans&a[j]);
				}
				cout<<ans;
				return 0;
			}
			i-=2;
		}
	}
	return 0;
}
