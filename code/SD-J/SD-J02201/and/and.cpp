#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[5000001];
bool cmp(int a,int b) {
	return a > b;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	sort(a+1,a+1+n,cmp);
	if(m == 1) {
		cout << a[1] << endl; // 10  
		return 0;	
	} else if (m == 2) {
		long long ans = 0;
		for(int i = 1;i <= n;i ++) {
			for(int j = i + 1;j <= n;j ++) {
				ans = max(ans,(a[i] & a[j]));
			}
		}
		cout << ans;
		return 0;
	} else {
	long long cnt = a[1];
		for(int i = 2; i <= m; i ++) {
			cnt = (cnt & a[i]);
		}
		cout << cnt << endl;
	}
	return 0;
}
// T3:Æ­·Ö Ô¤ÆÚ10-20 
