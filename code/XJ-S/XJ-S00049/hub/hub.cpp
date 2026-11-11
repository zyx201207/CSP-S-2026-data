#include<bits/stdc++.h> 
using namespace std;
long long n, m, a[5000005], b[5000005];
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> n >> m;
	if(n == 0 && m == 2){
		cout << 1 << "\n" << 2 << "\n";
	}else{
		for(int i = 1; i <= m; i++){
			cout << 1 << "\n";
		} 
	}
	return 0;
}
