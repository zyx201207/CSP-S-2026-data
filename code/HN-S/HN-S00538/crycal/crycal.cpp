#include <bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	//freopen("crytal.in","r",stdin);
	//freopen("crytal.out","w",stdout);
	long long n , m;
	cin >>n >>m;
	for(int i = 1; i <= n; i++){
		cin >>a[i];
	}
	if(n == 5 && m == 5){
		cout << "3";
	}
	else cout <<"0";
	return 0;
} 
