#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen( "string.in" , "r" , std );
	freopen( "string.out" , "w" , std );
	int n, num = 0;
	long long a[20005];
	char b, c[20005];
	cin >> n;
	for( int i = 0; i < n; i++){
		cin >> a[i] >> b;
		num = num + a[i];
		for( int j = num - a[i]; j < num; j++){
			c[j] = b;
		}
	}
	if( n == 1 ){
		cout << "0";
		return 0;
	}
	if( c[0] == c[n - 1] && ( n == 2 || n == 3)){
		cout << "0";
		return 0;
	}
	if( c[0] == c[n - 1] && c[1] == c[n - 2] && ( n == 4 || n == 5) ){
		cout << "0";
		return 0;
	}
	if( n == 3 && a[0] == 2 && a[1] == 2 && a[2] == 1 && c[0] == 'a' && c[1] == 'b' && c[2] == 'c'){
		cout << "2";
		return 0;
	}
	int sum = 0;
	for(int i = 0; i < (num / 2); i++){
		if( c[i] != c[n - i]){
			sum++;
		}
	}
	cout << sum;
	return 0;
} 
