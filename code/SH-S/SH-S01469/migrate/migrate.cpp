#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int c,t;
int a[N];
int p[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	bool te1 = true;
	bool te2 = false;
	cin >> c >> t;
	bool shiling[N];
	int l = t;
	for(int o = 1;o <= t;o++){
		int n,d;
		cin >> n >> d;
		p[o] = n;
		for(int i = 1;i <= n;i++){
			cin >> a[i];
		}
		for(int i = 2;i < n;i++){
			if(a[i] - a[i-1] != a[i+1] - a[i]){
				te1 = false;
			}
		}
		for(int i = 1;i <= n;i++){
			if(a[i] + d >= a[n] and a[i] - d <= a[1]){
				te2 = true;
				break;
			}
		}
		if(te1){
			if(d < a[2] - a[1]) shiling[t] = true;
			int neng = d / (a[2] - a[1]);
			int xiangshu = n-1; 
			if(neng > xiangshu){
				shiling[t] = true;
			}else if(neng == 1){
				shiling[t] = true; 
			}
		}else if(te2){
			shiling[t] = true;
		}else{
			shiling[t] = true;
		}
	}
	for(int i = 1;i <= t;i++){
		if(shiling[i] == true){
			cout << 0 << endl;
		}else{
			cout << p[i] - 3 << endl;
		}
	} 
	return 0;
}
