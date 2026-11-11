#include <iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	freopen ("migrate","r",stdin);
	freopen ("migrate","w",stdout);
	int c,t;
	cin >>c >>t;
	for (int i = 0; i <= t; i++){
		int n, d, ans, k;
		cin >> n >> d;
		int x(n);
		for (int j = 0; j <= n; j++){
			cin >>x[j];
		}
		
		k = x[n] - x[0];
		if (k % 2 == 0){
			ans++;
		}
		
	}
	cout << ans << endl; 
	cout.flush();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
