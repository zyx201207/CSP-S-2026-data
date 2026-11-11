#include <bits/stdc++.h>
using namespace std;
long long n;
bool o = 1;
string s;
string r;
char z;
long long t,q;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	q = 0;
	for(int i = 1;i <= n;i++){
		cin >> t >> z;
		for(int i = q;i < t+q;i++){
			s[i] = z;
		}
	}
	for(int i = s.length();i > 0;i--){
		for(int j = 0;j < s.length();i++){
			r[j] = s[i];
		}
	}
	for(int i = 0;i < s.length();i++){
		if(s[i]!=r[i]){
			o = 0;
		}
	}
	if(o){
		cout << 0;
	}
	else{
		cout << s.length()/2;
	}
	return 0;
}
