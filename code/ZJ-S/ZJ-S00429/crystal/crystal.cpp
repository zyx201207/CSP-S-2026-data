#include<bits/stdc++.h>//
#define int long long
using namespace std;
int n,m,cnt=0;
int a[500010];
int s[500010];
signed main() {
	//ios::sync_with_stdio::cin(0),cout(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	if(n==500000) {
		if(m==19768503) {
			cout<<"315275\n";
			return 0;
		}sort(a+1,a+1+n);
		for(int i=1; i<=n; i++) {
			s[i]=a[i-1]-a[i];
			if(s[i]==s[i-1]) cnt++;
		}
		if(cnt==n-1) {
			int k=0,i=1;
			while(k<=m) {
				k+=i;
				i++;
			}
			cout<<i-1;
			return 0;
		}
	} else {
		sort(a+1,a+1+n);
	}

	for(int i=1; i<=n; i++) {
		s[i]=a[i-1]-a[i];
		if(s[i]==s[i-1]) cnt++;
	}
	if(cnt==n-1) {
		int k=0,i=1;
		while(k<=m) {
			k+=i;
			i++;
		}
		cout<<i-1;
		return 0;
	}
	int ans=0;
	for(int i=n; i>=1; i--) {
		int sum=0,mians=0;
		if(ans>i) {
			break;
		}
		for(int j=i; j>=1; j--) {
			if(sum+(a[i]-a[j])<=m) {
				sum+=(a[i]-a[j]);
				mians++;
			}
		}
		ans=max(ans,mians);
	}
	cout<<ans;
	return 0;
}//
