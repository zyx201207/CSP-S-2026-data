#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;;
long long a[N];
long long n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(m == 1){
		sort(a + 1,a + 1 + n);
		cout << a[n] << endl;
		return 0;
	}
	if(m == n){
		long long qwq = a[1];
		for(int i = 2; i <= n; i++){
			qwq = (qwq & a[i]);
		}
		cout << qwq << endl;
		return 0;
	}
	if(m == 2){
		long long maxx = 0;
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				maxx = max(maxx,(a[i] & a[j]));
			}
		}
		cout << maxx << endl;
		return 0;
	}
	if(m == 3){
		long long maxx = 0;
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				for(int k = j + 1; k <= n; k++){
					maxx = max(maxx,(a[i] & a[j] & a[k]));
				}
			}
		}
		cout << maxx << endl;
		return 0;
	}
	if(m == 4){
		long long maxx = 0;
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				for(int k = j + 1; k <= n; k++){
					for(int q = k + 1; q <= n; q++){
						maxx = max(maxx,(a[i] & a[j] & a[k] & a[q]));
					}
				}
			}
		}
		cout << maxx << endl;
		return 0;
	}
	if(m == 5){
		long long maxx = 0;
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				for(int k = j + 1; k <= n; k++){
					for(int q = k + 1; q <= n; q++){
						for(int w = q + 1; w <= n; w++){
							maxx = max(maxx,(a[i] & a[j] & a[k] & a[q] & a[w]));
						}
					}
				}
			}
		}
		cout << maxx << endl;
		return 0;
	}
	if(m == (n - 1)){
		long long qwe = a[1];
		long long qwr = a[2];
		for(int i = 2; i <= n; i++){
			qwe &= a[i];
		}
		for(int i = 3; i <= n; i++){
			qwe &= a[i];
		}
		long long maxx = max(que,qwe);
		cout << maxx << endl;
		return 0;
	}
	return 0;
}
