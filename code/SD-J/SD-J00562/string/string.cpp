#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[N], b[N];
string s[N], s2[N];
queue <map<char, int>> q;
stack <map<char, int>> st;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, cnt = 0;
	cin >> n;
	string ss = "";
	for(int i = 1; i <= n; i ++){
		cin >> a[i] >> s[i];
		b[n - i + 1] = a[i];
		s2[n - i + 1] =  s[i]; 
		int x = a[i];
		for(int j = 0; j < a[i]; j ++) ss += s[i];
	}
	int l = 1, r = ss.size();
	for(int i = 0; i < r / 2; i ++){
		if(ss[i] != ss[r - i - 1]){
			cnt ++;
		}
	}
	cout << cnt;
	return 0;
}
