#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll p[int(2*1e5)+3];

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >>m;
//	int b[n];
//	int cnt[n+1];
//	for(int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//	for(int i = 1;i <= n; i++) {
//		int t = 1;
//		for(int j = i; j <=n;j++){
//			b[t++] = a[j];
//			if((j > i&&a[j]==a[j - 1])){
//				b[t] = 0;
//				t--;
//			}		
//		}
//		int c[n+1];
//		for(int d = 0; d < t; d++){
//			c[b[i]]++;
//		}
//		for(int d = 1; d <= m; d++){
//			if(c[d] >0) cnt[d]++;
//		}
//		
//	}
//	for(int d = 1; d <= m; d++){
//			cout << cnt[d];
//	}

	for(int i = 0; i < m; i++) {
		cout << n << " ";
	}
	

	
	return 0;
}

