#include<bits/stdc++.h>
using namespace std;
int n;
int a[10000001];
string s[10000001];
int main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	cin >> n;
	for(int i=  1; i <= n; i++){
		cin >> a[i] >> s[i];
	}
	if(n = 1){
		cout << '0';
	}else{
	if( s[1] == s[2])
	cout <<'0';
	}
	return 0;
} 
