#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
bool f(int a,int b) {
	return a>b;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	long long mi=a[1];
	sort(a,a+n,f);
	long long sum=0;
	while(sum>m) {
		sum=0;
		for(int i=1; i<n; i++) {
			sum+=a[0]-a[i];
		}
	}
	
	cout << sum;
	return 0;
}
