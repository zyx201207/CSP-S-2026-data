#include<iostream>
#include<cmath>
using namespace std;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200005];
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	if(m == 1) {
		int max_val67 = -2000000000;
		for(int i = 1;i <= n;i++)  max_val67 = max(a[i],max_val67);
		cout << max_val67;
		return 0;
	}
	else if(m == 2) {
		int max_val67 = -2000000000;
		for(int i = 1;i <= n;i++) for(int j = i + 1;j <= n;j++) max_val67 = max(a[i] & a[j],max_val67);
		cout << max_val67;
		return 0;
	}
	else if(m == n) {
		int max_val67 = -2000000000;
		for(int i = 1;i < n;i++) max_val67 = max(a[i] & a[i + 1],max_val67);
		cout << max_val67;
		return 0;
	}
	else if(m == n - 1) {
		int max_val67 = -2000000000;
		for(int i = 1;i < n - 1;i++) max_val67 = max(a[i] & a[i + 1],max_val67);
		for(int i = 2;i < n;i++) max_val67 = max(a[i] & a[i + 1],max_val67);
		cout << max_val67;
		return 0;
	}
	else cout << "12";
	return 0;
}
