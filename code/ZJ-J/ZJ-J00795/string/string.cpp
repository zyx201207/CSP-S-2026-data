#include<bits/stdc++.h>
using namespace std;
int n; string str;
int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	while(n--){
		int a; char c;
		cin >> a >> c;
		while(a--){
			str += c;
		}
	}
	int cnt = 0;
	for(int i = 0; i < str.length() / 2; i++){
		if(str[i] != str[str.length() - i - 1]) cnt++;
	}
	cout << cnt;
	return 0;
}