#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e6 + 10;
int c, t;
int n, d;
int a[N];
int flagx[N];
int flagy[N];
bool flagxx[N];
bool flagyy[N];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1;i <= n; i++){
			cin >> a[i];
		}
		int l = 0, r = 0;
		for(int i = 1;i <= n; i++){
			for(int j = i;j <= n; j++){
				if((a[j] - a[i]) % 2 != 0){
					l++;
					r++;
					flagx[l] = a[i];
					flagy[r] = a[j];
					
					cout << a[i] << " " << a[j] << " "; 
				} 
			}
		}
		cout << l << "->" << r;
		int cnt = 0;
		for(int i = 1;i <= l; i++){
			for(int j = 1;j <= r; j++){
				if(flagx[i] + d < flagy[j] && flagxx[flagx[i]] == 0 && flagyy[flagy[j]] == 0){
					flagxx[flagx[i]] = 1;
					flagyy[flagy[j]] = 1;
					cout << flagx[i] << " " << flagy[j];
					cnt++;
				}
			}
		}
		memset(flagxx, 0, sizeof(flagxx));
		memset(flagyy, 0, sizeof(flagyy));
		cout << cnt << '\n';
	}
	return 0;
}
