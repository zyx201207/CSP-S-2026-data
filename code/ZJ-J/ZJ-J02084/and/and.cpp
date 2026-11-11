#include<bits/stdc++.h>
using namespace std;
long long a[200020];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long ans=0,tn_1=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(i==1) {
			ans=a[i];
		} else {
			ans=ans&a[i];
		}
	}
	if(m==n) {
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	if(m==1) {
		cout<<a[n];
		return 0;
	}
	if(m==n-1) {
		for(int i=n; i>1; i--) {
			if(i==n) {
				tn_1=a[i];
			} else {
				tn_1=tn_1&a[i];
			}
		}
		for(int j=n; j>=min(n-n/10000,20000); j--) {
			long long cnt=a[1];
			for(int i=1; i<=n; i++) {
				if(i!=j)cnt&a[i];
			}
			tn_1=max(cnt,tn_1);
		}
		cout<<tn_1;
		return 0;
	}
	int q=a[n];
	for(int i=n; i>=n-m+1; i--) 
	{
		q=q&a[i];
	}
	cout<<q;
	return 0;
}