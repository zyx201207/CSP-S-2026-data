#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ma = -1;
	int a[N];
	cin >> n >> m;
	for (int i = 0;i < n;i++){
		cin >> a[i];
		ma = max(ma,a[i]); 
	}
	if (m == 1){
		cout << ma << "\n";
		return 0;
	}
	else if (m == 2){
		int ans = -1;
		for (int i = 0;i < n;i++){
			for (int j = i+1;j < n;j++){
				int c = a[i]&a[j];
				ans = max(ans,c);
			}
		}
		cout << ans << "\n";
		return 0;
	}
	else if (m == n){
		int cnt = a[0];
		for (int i = 1;i < n;i++){
			cnt = (cnt & a[i]);
		}
		cout << cnt << "\n";
		return 0;
	}
	else if (m == n-1){
		int sum = 0,fl[N],a2 = -1;
		int si = 0; 
		if (si+1 < n){
			sum = a[si+1];
		}
		else if (si-1 > 0){
			sum = a[si-1];
		}
		for (int i = 0;i < n;i++){
			if (i != si){
				sum = (sum & a[i]);
				a2 = max(a2,sum);
			}
		}
		cout << a2 << "\n";
		return 0;
	}
	return 0;
}
