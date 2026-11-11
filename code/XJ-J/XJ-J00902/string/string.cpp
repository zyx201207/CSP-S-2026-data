#include <iostream>
using namespace std;
int main(){
	//freopen("string.in", "r", stdin);
	//freopen("string.out", "w", stdout);
	long long n, cnt = 0;
	string s = "";
	cin >> n;
	while(n--){
		char a;
		long long b;
		cin >> a >> b;
		while(b--){
			s += a;
		}
	}
	for(long long i = 0; i < s.size() / 2; i++){
		if(s[i] != s[s.size() - i + 1]){
			s[i] = s[s.size() - i + 1];
			cnt++;
		}
	}
	cout << cnt; 
	return 0;
}
