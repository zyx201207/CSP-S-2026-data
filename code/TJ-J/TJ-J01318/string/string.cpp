#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
vector<char> s;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin>>n;
	while(n){
		int num;
		char c;
		cin>>num>>c;
		while(num){
			s.push_back(c);
			num--;
		}
		n--;
	}
	int l = s.size();
	int cnt = 0;
	for(int i = 0; i < l / 2; i++){
		if(s[i] != s[l - 1 - i]) cnt++;
	}
	cout<<cnt;
	return 0;
}
