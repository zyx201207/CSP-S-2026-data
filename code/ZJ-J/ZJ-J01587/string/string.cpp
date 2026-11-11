#include <bits/stdc++.h>
using namespace std;

long long n,a,cnt;
char c;
string s;

int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a >> c;
		while(a--){
			s += c;
		}
	}
	if(n == 1){
		cout << 0;
		return 0;
	}
	if(n == 2){
		if(s[0] != s[s.size() - 1]){
			cout << 1;
			return 0;
		}else{
			cout << 0;
			return 0;
		}
	}
	for(int i = 1; i <= (s.size() - 1)/2; i++){
		if(s[i] != s[s.size() - i + 1]){
			cnt++;
		}
	}
	cout << cnt;
	
	return 0;
}
