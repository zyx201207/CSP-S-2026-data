#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long n, m;
long long a[N], arr[N], tot[N], all[N];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i=2;i<=n;i++){
		arr[i-1] = a[i] - a[i - 1];
		//cout << arr[i-1] << " ";
	}
	//cout << '\n';
	for(int i=n;i>=1;i--){
		tot[i] = tot[i + 1] + arr[i];
		//cout << tot[i] << " ";
	}
	//cout << '\n';
	for(int i=1;i<=n;i++){
		all[i] = all[i - 1] + tot[i];
		//cout << all[i] << " ";
	}
	//cout << '\n';
	
	bool flag = 0;
	int l = 1, r = n, cnt = 0;
	long long arr_x = all[r - 1] - all[l - 1] - (r - l) * tot[r];
	while(!flag){
		arr_x = all[r - 1] - all[l - 1] - (r - l) * tot[r];
		if(arr_x > m){
			if(arr[l] > arr[r - 1]){
				l++;
			}else{
				r--;
			}
			cnt++;
		}else{
			flag = 1;
		}
		//cout << arr_x << " " << cnt << " " << l << " " << r << '\n';
	}
	cout << n - cnt;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
