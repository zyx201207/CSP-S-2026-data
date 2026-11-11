#include<iostream>
using namespace std;
int main(){
	int n,m;
	cin >> n >> m;
	int a[n];
	int k[n]; 
	cin >> k[n];
	if(k[1]==k[n]){
		cout << n-1;
	}else if(k[1]==k[n-1]){
		cout << n-1;
	}else{ 
		cout << n;
	}
	cout << " " << n-3 << " " << n;
}
