#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll n;
string s;

ll s_len;

ll ans;

bool check(char a, char b){
	if(a == b) return true;
	else return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	
	//输入&拼接 
	for(int i = 1; i <= n; i++){
		int tmp;
		char a;
		cin >> tmp >> a;
		//拼接 
		for(int j = 1; j <= tmp; j++){
			s += a;
		}
	}
	
	s_len = s.size();
	
	
	// 对于字符串输入排列的测试 
//	cout << "----------------------------\n";
//	for(int i = 0; i <= s_len; i++){
//		cout << s[i] << " ";
//	}
//	cout << "\n========================================\n\n";
	
	
//	cout << s[s_len] << "    \n==\n";
 
	for(int i = 0; i <= (s_len) / 2 ; i++){
		char a = s[0 + i];
		char b = s[s_len - 1 - i];
		
		if( !check(a,b) ){
			ans ++;
		}
	}
	
	cout << ans << '\n';
	return 0;
}
