#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char c[200005], tu[2000005], tU[2000005];
long long ans1, ans2, num;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>c[i];
		for(int j=1; j<=a[i]; j++) {
			tu[j+num]=c[i];
			tU[j+num]=c[i];
		}
		num+=a[i];
	}
	for(int i=1; i<=num; i++) {
		if(tu[i]!=tu[num-i+1]) {
			ans1++;
			tu[num-i+1]=tu[i];
		}
	}
	for(int i=num; i>=1; i--) {
		if(tU[i]!=tU[num-i+1]) {
			ans2++;
			tU[num-i+1]=tU[i];
		}
	}
	cout<<min(ans1, ans2);
	return 0;
} 

