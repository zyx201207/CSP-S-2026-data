#include <bits/stdc++.h>
using namespace std;
long long n;
string s = "";
bool pan(string s){
	string s2 = "";
	string cun = s;
	for(long long i = cun.size() - 1; i >= 0 ; i--){
		s2 += cun[i];
	}
	if(s == s2){
		return 1;
	}
	return 0;
}

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	
	for(long long i = 1;i <= n; i++){
		long long x;
		char ch;
		cin >> x >> ch;
		for(long long j = 0;j < x; j++){
			s += ch;
		}
	}
	
	if(pan(s)){
		cout << 0;
		return 0;
	}
	
	
	long long cnt = 0;
	char gai = s[0];
	string ss = s;
	for(long long i = s.size() - 1; i >= 0; i--){
		
		ss[i] = gai;
		//cout << ss << '\n';
		cnt++;
		if(pan(ss)){
			break;
		}
	}
	long long t = s.size();
	long long cnt2 = 0;
	char gai2= s[t - 1];
	string s22 = s;
	for(long long i = 0;i < s.size(); i++){
		
		s22[i] = gai2;
		//cout << ss << '\n';
		cnt2++;
		if(pan(s22)){
			break;
		}
	}
	cout << min(cnt2, cnt);
	return 0;
}
