#include <bits/stdc++.h>
using namespace std;
long long a[1000000005];
char b[1000000005];
int main(){
	long long n;
	cin >> n;
	string s;
	for (int i = 1;i <= n;i++){
		cin >> a[i] >> b[i];
	}
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= a[i];j++){
			s += b[i];
		}
	}
	
	return 0;
}