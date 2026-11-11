#include<bits/stdc++.h>
using namespace std;
string s1, s2;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int a;
		string s;
		cin >> a >> s;
		for (int i = 1; i <= a; i++){
			s1+=s;
		}
	}
	int cnt = 0;
	s2 = s1;
	reverse(s2.begin() - 1,s2.end() + 1);
	for (int i = s1.size() / 2; i <= s1.size()- 1; i++){
		if (s2[i] != s1[i]) cnt++;
	}
	cout << cnt;
	return 0;
}
