#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,mi = 0,ma = 0,sum = 0;
	string s;
	char b[2005];
	int a[10005];
	
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> a[i] >> b[i];
		sum += a[i];
		for(int i = 1; i <= a[i]; i ++){
			s += b[i];
		}
	}
	
	if(n == 1){
		cout << 0;
		return 0;
	}
	
	if(n <= 2){
		if(b[1] == b[2]){
			cout << 0;
		}
		else{
			mi = min(a[1],a[2]);
			cout << mi;
		}
		return 0;
	}
	
	if(n <= 10){
		ma = a[1];
		for(int i = 1; i <= n; i ++){
			ma = max(ma,a[i]);
		}
		if(sum - ma > ma)
			cout << ma;
		if(sum - ma < ma)
			cout << sum - ma;
	}
	return 0;
} 
