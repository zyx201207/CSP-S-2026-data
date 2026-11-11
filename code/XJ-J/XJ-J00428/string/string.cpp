#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n;
int a[N]; char c[N];
int ans;
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin>>a[i]>>c[i];
	}
	int i=1, j=n;
	while(true) {
		if(c[i]==c[j]) {
			if(a[i]>a[j]) a[i]-=a[j], j--;
			else if(a[i]<a[j]) a[j]-=a[i], i++;
			else i++, j--;
		}  else {
			if(a[i]>a[j]) a[i]-=a[j], ans+=a[j], j--;
			else if(a[i]<a[j]) a[j]-=a[i], ans+=a[i], i++;
			else ans+=a[i], i++, j--;
		}
		if(i>=j) break;
	} 
	cout << ans << endl;
}
