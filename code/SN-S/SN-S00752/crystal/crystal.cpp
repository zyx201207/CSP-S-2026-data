#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,sum=0;
	cin >> n >> m;
	cout << n << " " << m << endl;
	long a[n];
	long b;
	for (long i=0;i<n;i++) {
		cin >> a[i];
		b+=a[i];
	}
	sort(a,a+n);
//	for (int i=0;i<n;i++) {
//		cout << a[i] << " ";
//	}
//	cout << endl;
	for (long i=n-1;i>=0;i--) {
		b-=a[i];
//		cout << b << " " ;
//		cout << a[i]*i-b << " " << endl;
		if (a[i]*i-b <= m) {
//			cout << endl;
			cout  << sum << endl;
			break;
		}
	}
	return 0;
} 
