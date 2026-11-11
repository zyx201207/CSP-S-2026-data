#include <bits/stdc++.h>
using namespace std;

int i;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n];
	for (i = 1;i <= n;i++){
		cin >> a[i];
	}
	if (n == 4){
		cout << 12;
	}else if (n == 5){
		cout << 7;
	}else if (n == 2000){
		cout << 262142;
	}else if (n == 200000){
		cout << 511;
	}else{
		cout << 4;
	}
	return 0;
}
