#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	int n;
	long long m;
	int a[100005];

	cin>>n>>m;

	for(int i=0; i<n; i++) {
		cin>>a[i];
	}

	sort(a,a+n);

	int mid=(a[0]+a[n-1])/2;
	int midd,minl=10;
	for(int i=0; i<n; i++) {
		if(mid>a[i]) {
			if(mid-a[i]<minl) {
				minl=mid-a[i];
				midd=i;
			}
		} else if(mid<a[i]) {
			if(a[i]-mid<minl) {
				minl=a[i]-mid;
				midd=i;
			}
		}
	}

	int l[100005];
	for(int i=0; i<n; i++) {
		if(a[i]<a[midd]) {
			l[i]=a[midd]-a[i];
		} else if(a[i]>a[midd]) {
			l[i]=a[i]-a[midd];
		}
	}
	sort(l,l+n);

	int ans=0;
	long long num=0;
	for(int i=0; i<=m; i++) {
		if((long long)num+l[i]<=m) {
			ans++;
			num+=l[i];
		} else {
			break;
		}
	}
	cout<<ans;
	return 0;
}
