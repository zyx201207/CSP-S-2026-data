#include<bits/stdc++.h>
using namespace std;

	int n;
	long long m;
	long long a[500010];
	int ans = 1;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	
	bool p = 0;
	for (int i = 1;i <= n;i++){
		if (a[i] != i){
			p = 1;
		}
	}
	if (p == 0){
		bool pp = 0;
		long long sum = 0;
		for (int i = 1;i < n;i++){
			sum += i;
			if (sum > m){
				ans = i;
				pp = 1;
				break;
			}
		}
		if (pp == 0){
			ans = n;
		}
		cout << ans << endl;
		return 0;
	}
	
	bool b = 0;
	for (int i = 3;i <= n;i++){
		if (a[i] - a[i - 1] != a[2] - a[1]){
			b = 1;
		}
	}
	if (b == 0){
		bool bb = 0;
		long long sum = 0;
		for (int i = 1;i < n;i++){
			sum += i * (a[2] - a[1]);
			if (sum > m){
				ans = i;
				bb = 1;
				break;
			}
		}
		if (bb == 0){
			ans = n;
		}
		cout << ans << endl;
		return 0;
	}
	
	
	for (int i = 1;i <= n;i++){
		long long t = m;
		bool s = 0;
		for (int j = i - 1;j >= 1;j--){
			if (t >= a[i] - a[j]){
				t -= (a[i] - a[j]);
			}
			else{
				ans = max(ans,i - j);
				s = 1;
				break;
			}
		} 
		if (s == 0){
			ans = max(ans,i);
		}
	}      
	cout << ans << endl;                
	return 0;
} 
