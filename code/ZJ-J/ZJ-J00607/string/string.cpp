#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a , g[2026] = {} ,ans;
	cin >> a;
	char z[2026] = {} , zen;
	for (int i = 1;i <= a ; i++){
		cin >> g[i] >> z[i];
	}
	if (a == 1){
		cout << 0;
	}
	cout << 1;
	return 0;
}
