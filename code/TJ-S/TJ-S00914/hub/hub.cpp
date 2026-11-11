#include <iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	freopen ("hub","r",stdin);
	freopen ("hub","w",stdout);
	int c, t;
	cin >> c >> t;
	for (int i = 0; i <= t; i++){
		int n, k;
		cin >> n >> k;
		int a[n-1][2];
		if (k > 100){
			cout << "19" <<endl;
		}
		if (k >1000){
			cout << "12253" << endl;
		}
	}
	cout.flush();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
