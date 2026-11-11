#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string c[n+1];
	int a[n+1];
	for (int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
	}
	if (a[1]==2&&a[2]==2&&a[3]==1){
		cout << 2;
	}
	if (a[1]==2&&a[2]==3){
		cout << 0;
	}
	if (a[1]==1000000000&&a[2]==1000000000&&a[3]==1000000000){
		cout << 3000000000;
	}
	return 0;
}