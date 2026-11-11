#include <bits/stdc++.h>
using namespace std;
long long n, m, a[222222], maxn;
int main(){
	freopen("and.in", "r" ,stdin);
	freopen("and.out", "w" ,stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		maxn = max(a[i], maxn);
	}
	if(m == 1){
		cout << maxn;
	}else if(m == 2){
		maxn = 0;
		for(int i = 1; i < n; i++){
			for(int j = 1; j <= n; j++){
				if(i != j){
					long long ii = a[i], jj = a[j], z = 0, cnt = 0;
					while(ii && jj){
						if(ii == jj){
							cnt = ii;
							break;
						}
						if(ii % 2 == jj % 2){
							cnt += pow(2, z);
						}
						z++;
						ii /= 2;
						jj /= 2;
						
					}
					cout << endl;
					maxn = max(maxn, cnt);
				}
			}
		}
		cout << maxn;
	}else{
		sort(a + 1, a + n + 1);
		cout << a[n - m];
	}
	return 0;
}
