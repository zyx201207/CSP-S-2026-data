#include <bits/stdc++.h> 
using namespace std;

int n;
string s;

bool hw(string s){
	long long l = s.size();
	for(int i = 0; i < l/2; i++){
		if(s[i] != s[l-i-1]) return false;
	}
	return true;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		long long x;
		char c;
		cin >> x >> c;
		for(int i = 1; i <= x; i++) s += c;
	}
	if(hw(s)){
		cout << "0";
		return 0;
	}
	long long l = s.size();
	long long ans = 0;
	for(int i = 0; i < l/2; i++){
		if(s[i] != s[l-i-1]) ans++;
	}
	cout << ans;
	cout << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
