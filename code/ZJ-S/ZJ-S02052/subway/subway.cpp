#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int n;
	int ans=0;
	long long a[50004];
	long long m;
	cin>>n>>m;
	for(int i=1; i<n; i++) {
		cin>>a[i];
	}
	for(int i=a[0]; i<=a[n]+n; i++) {
		for(int j=0; j<n; j++) {
			if(a[j]<=i ) {
				for(int k=0; k<n; k++)
					ans+=i-a[j];
				if(ans==m) {
					cout<<ans;
					return 0;
				}
			}
		}
	}
	for(int i=a[0]; i<=a[n]+n; i++) {
		for(int j=0; j<n; j++) {
			if(a[j]<=i ) {
				for(int k=0; k<n; k++)
					ans+=i-a[j];
				if(ans==m) {
					cout<<ans;
					return 0;
				}
			}
		}
	}
	for(int i=a[0]; i<=a[n]+n; i++) {
		for(int j=0; j<n; j++) {
			if(a[j]<=i ) {
				for(int k=0; k<n; k++)
					ans+=i-a[j];
				if(ans==m) {
					cout<<ans;
					return 0;
				}
			}
		}
	}
	for(int i=a[0]; i<=a[n]+n; i++) {
		for(int j=0; j<n; j++) {
			if(a[j]<=i ) {
				for(int k=0; k<n; k++)
					ans+=i-a[j];
				if(ans==m) {
					cout<<ans;
					return 0;
				}
			}
		}
	}
	for(int i=a[0]; i<=a[n]+n; i++) {
		for(int j=0; j<n; j++) {
			if(a[j]<=i ) {
				for(int k=0; k<n; k++)
					ans+=i-a[j];
				if(ans==m) {
					cout<<ans;
					return 0;
				}
			}
		}
	}
	for(int i=a[0]; i<=a[n]+n; i++) {
		for(int j=0; j<n; j++) {
			if(a[j]<=i ) {
				for(int k=0; k<n; k++)
					ans+=i-a[j];
				if(ans==m) {
					cout<<ans;
					return 0;
				}
			}
		}
	}
	for(int i=a[0]; i<=a[n]+n; i++) {
		for(int j=0; j<n; j++) {
			if(a[j]<=i ) {
				for(int k=0; k<n; k++)
					ans+=i-a[j];
				if(ans==m) {
					cout<<ans;
					return 0;
				}
			}
		}
	}
	for(int i=a[0]; i<=a[n]+n; i++) {
		for(int j=0; j<n; j++) {
			if(a[j]<=i ) {
				for(int k=0; k<n; k++)
					ans+=i-a[j];
				if(ans==m) {
					cout<<ans;
					return 0;
				}
			}
		}
	}
	for(int i=a[0]; i<=a[n]+n; i++) {
		for(int j=0; j<n; j++) {
			if(a[j]<=i ) {
				for(int k=0; k<n; k++)
					ans+=i-a[j];
				if(ans==m) {
					cout<<ans;
					return 0;
				}
			}
			if(a[j]<=i ) {
				for(int k=0; k<n; k++)
					ans+=i-a[j];
				if(ans==m) {
					cout<<ans;
					return 0;
				}
			}
		}
	}

	cout<<ans;
	return 0;
}

