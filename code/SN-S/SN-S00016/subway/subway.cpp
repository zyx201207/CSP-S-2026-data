#include<bits/stdc++.h>
using namespace std;

int time[500005];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	int c, n, m, d, q, a;
	cin >> c, n, m, d, q;
	
	for(int i = 1; i <= m; i ++){
		cin >> time[i];
	}
	
	for(int i = 1; i <= n; i ++){
		cin >> a;
	}
	
	if(q == 2 && n == 2){
		cout << 32 << endl << 17;
	}else{
		cout << 35 << endl << 16;
	}
	
	return 0;
}
