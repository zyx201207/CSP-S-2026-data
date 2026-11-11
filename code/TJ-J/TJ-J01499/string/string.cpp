#include <bits/stdc++.h>
using namespace std;
long long n,sum;
long long a[200005];
char c[200005];
string str;
int main () {
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i] >> c[i];
	}
//	int s=1;
//	for (long long  i=0;i<n;i++){
//		for (long long  j=1;j<=a[i];j++){
//		 	str[s]=c[i];
//		 	s++;
//		}
//	}
//	long long  l=1,r=s-1;
	int l=0 ,r=n-1;
	while(l<r) {
		if (c[l]!=c[r]) {
			if (a[l]>a[r]) {
				a[l]-=a[r];
				sum+=a[r];
				r--;

			} else if (a[r]>a[l]) {
				a[r]-=a[l];
				sum+=a[l];
				l++;

			} else {
				sum+=a[l];
				l++;
				r--;
			}

		}
		if (c[l]==c[r]) {
			if (a[l]>a[r]) {
				a[l]-=a[r];

				r--;

			} else if (a[r]>a[l]) {
				a[r]-=a[l];
				l++;

			} else {
				l++;
				r--;
			}

		}

	}
	cout << sum;

	return 0;
}
