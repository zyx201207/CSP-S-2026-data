#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
const int N = 5e5 + 5;
int a[N];
int c[5005][5005];
int maxn;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n>> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for(int i = 1;i < n;i++){
		for(int j = i + 1;j <= n;j++){
			c[i][j] = abs(a[i] - a[j]);
			c[j][i] = c[i][j];
		}
	}
	for(int k = 1;k <= n;k++){
		int l = k - 1, r = k + 1;
		int cnt = 1;
		while(l >= 1 || r <= n){
			if(l < 1){
				l = -1;
			}
			if(r > n){
				r = -1;
			}
			if(l == -1 && r == -1){
				break;
			}
			if(l != -1 && r != -1){
				if(c[k][l] > c[k][r]){
					if(m >= c[k][r]){
						m -= c[k][r];
						r++;
						cnt++;
					}else{
						r = -1;
					}
				}else{
					if(m >= c[k][l]){
						m -= c[k][l];
						l--;
						cnt++;
					}else{ 
						l = -1;
					}
				}
			}else if(l == -1){
				if(m >= c[k][r]){
					m -= c[k][r];
					r++;
					cnt++;
				}else{
					r = -1;
				}
			}else{
				if(m >= c[k][l]){
					m -= c[k][l];
					l--;
					cnt++;
				}else{ 
					l = -1;
				}
			}
		}
		maxn = max(maxn, cnt);
	}
	cout << maxn;
	return 0;
}
