#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r","stdin");
	freopen("string.out","w","stdout");
	int n,c,count1 = 0;
	string a,b,d;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> c >> b;
		for(int i = 0; i < c; i++){
			a = a + b;
		}
	}
	for(int i = 0; i < n/2; i++){
		d = d + a[i];
	}
	for(int i = 0; i < n/2; i++){
		if(d[i] == a[n-1-i]) continue;
		else count1++;
	}
	cout << count1;
}
