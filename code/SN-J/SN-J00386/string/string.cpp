#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	string s;
	for(int i = 1; i <= n; i ++) {
		int a;
		char c;
		cin >> a >> c;
		for(int j = 1; j <= a; j ++) s = s + c;
	}
	long long cnt = 0,len = s.size();
	for(int i = 0; i < len / 2; i ++) if(s[i] != s[len - i - 1]) cnt ++;
	cout << cnt;
	return 0;
}
