#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+10; 
long long a[MAXN];

bool cmp(long long d, long long k){
	int t = 30;
	for(int i = t; i >= 0; i--){
		if(((d>>i) & 1) && ((k>>i) & 1)){
			continue;
		}else if((d>>i) & 1){
			return 1;
		}else if((k>>i) & 1){
			return 0;
		}else{
			continue;
		}
	}
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	//sort(a+1, a+n+1, cmps);
	for(int i = 1; i <= n; i++){
		bool f = false;
		for(int j = i; j <= n; j++){
			if(!cmp(a[j], a[j+1])){
				swap(a[j], a[j+1]);
				f = true;
			}
		}
		if(!f) break;
	}
	
	long long ans = a[1];
	/*cout << ans << " ";
	for(int i = 2; i <= n; i++){
		cout << a[i] << " ";
	}*/
	for(int i = 2; i <= m; i++){
		ans &= a[i];
	}
	
	// cout << endl;
	
	cout << ans;
	
	return 0;
}
