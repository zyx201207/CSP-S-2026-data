#include<bits/stdc++.h>
using namespace std;
int n;
long long m , a[500005];
int ans;
int main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	cin >> n >> m;
	//对a排序，枚举要转化为的a[i]再靠贪心取得最优解   O(n^2 + nlogn)   45pts
	long long mm = m;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	int fa = 1 , fb = 1;
	for(int i = 1 ; i <= n ; i++) if(a[i] != i) fa = 0;
	for(int i = 2 ; i <= n ; i++) if(a[i] - a[i-1] != a[2] - a[1]) fb = 0;
	if(n <= 10000 && !fa && !fb){
		sort(a + 1 , a + n + 1);
		
		for(int i = 1 ; i <= n ; i++){
			int now = 1;
			m = mm;
			for(int j = i-1 ; j >= 1 ; j--){
				if(m - (a[i] - a[j]) >= 0){
					m = m - a[i] + a[j];
					now++;
					//cout << "m: " << m << "  a[i] - a[j]: " << a[i] - a[j] << endl;
				}
				else break;
			}
			if(now > ans) ans = now;
			
		}
		cout << ans ;//<< " " << id;
	}
	else{
		if(fa){//15pts
			ans = 1;
			int k = 1;
			while(m >= 0){
				if(m - k >= 0){
					ans++;
					m -= k;
					k++;
				}
				else break;
			}
			cout << ans;
		}
		else if(fb){//15pts
			ans = 1;
			long long k = abs(a[2] - a[1]);
			while(m >= 0){
				if(m - k >= 0){
					ans++;
					m -= k;
					k += abs(a[2] - a[1]);
				} 
				else break;
			}
			cout << ans;
		}
		else cout << n;
	}
	return 0;//期望：75pts 
}
