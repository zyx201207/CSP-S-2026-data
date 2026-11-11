#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		int a;
		char c;
		cin >> a >> c;
		for(int j = 1; j <= a; j++){
			s = s + c;
		}
	}
	int len = s.size() - 1, cnt = 0; 
	for(int i = 0; i <= s.size() / 2; i++){
		if(s[i] != s[len - i]){
			cnt ++;
		}
	}
	cout << cnt;
	return 0;
}

