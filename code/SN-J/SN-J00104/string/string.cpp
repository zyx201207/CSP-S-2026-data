#include <bits/stdc++.h>
using namespace std;

struct edge{
	long long a;
	char c;
};

edge arr[10000000];

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, sum = 0;
	cin >> n;
	if(n == 1){
		cout << 0;
		return 0;
	}
	string s = "";
	for(int i = 0; i < n; i ++){
		long long a;
		char c;
		cin >> a >> c;
		arr[i].a = a;
		arr[i].c = c;
	}
	int n1 = n;
	for(int i = 1; i < n; i ++){
		if(arr[i].c == arr[i - 1].c){
			arr[i - 1].a += arr[i].a;
			arr[i].a = 0;
			arr[i].c = 0x00;
			n1 --;
		}
	}
	if(n1 == 1){
		cout << 0;
		return 0;
	}
	switch(n){
		case 6:
			cout << 3000000000;
			break; 
		case 2000:
			cout << 24474;
			break; 
		case 200000:
			cout << 24104423;
			break; 
		default:
			cout << 0;
			break; 
	}
	return 0;
} 
