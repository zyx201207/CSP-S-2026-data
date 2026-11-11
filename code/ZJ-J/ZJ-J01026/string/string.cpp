#include <bits/stdc++.h>
using namespace std;
long long n,cnt;
string s;
bool fun(){
	int l = 0,r = s.size()-1;
	while(l <= r){
		if(s[l] != s[r]) cnt++; 
		l++;r--;
	}
	return 0;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		int t;
		char k;
		cin >> t >> k;
		for(int j = 1;j <= t;j++) s += k;
	}
	fun();
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
