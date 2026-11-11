#include <bits/stdc++.h>
using namespace std;
long long judge(string s){
	long long sum = 0, p = 0, q = s.size()-1;
	while(p != q){
		if(s[p++] != s[q--]) sum++;
	}
	return sum;
}
int main(){
	string s;
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		long long a;
		char c;
		cin >> a >> c;
		for(long long j = 1; j <= a; j++) s += c;
	}
	cout << judge(s);
}
		
