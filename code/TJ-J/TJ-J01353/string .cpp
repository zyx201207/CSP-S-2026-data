#include <iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >>n;
	int a[n];
	int ans;
	for (int i = 0; i<= n; i++){
		cin>> a[i];
	}
	for (int i = 0; i <= n; i++) {
		if (a[i] != a[n - i]){
			ans ++;
		}
	}
	cout <<ans;

	return 0;
}
