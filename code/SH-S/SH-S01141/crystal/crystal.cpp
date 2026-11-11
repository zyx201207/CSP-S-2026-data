#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
long long n, m, a[maxn], cha[maxn];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> a[i];
	bool flag = 1;
	long long cha = a[1] - a[0];
	for(int i = 0; i < n - 1; i++){
		if(a[i + 1] - a[i] != cha) flag = 0;
	}
	int ans;
	if(flag){
		if(cha){
			for(int i = 0; i < n; i++) {
				if(((i * i + i) / 2) > m){
					ans = i;
					break;
				} 
			}
		}else{
			for(int i = 0; i < n; i++) {
				if(((a[n - 1] * a[n - 1] - 1) / cha + a[n - 1] + 1) / 2 > m){
					ans = i;
					break;
				} 
			}
		}
		cout << ans;
		return 0; 
	}
	cout << m / 2;
	return 0;
}  
