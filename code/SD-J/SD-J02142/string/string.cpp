#include <bits/stdc++.h>
using namespace std;
struct child{
	long long id;
	char c;
}b[222222];
long long n, a[33][2], maxn, ans;
string s = "0";
int main(){
	freopen("string.in", "r" ,stdin);
	freopen("string.out", "w" ,stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> b[i].id >> b[i].c;
		maxn = max(maxn, b[i].id);
	}
	if(n * maxn < 100000000){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= b[i].id; j++){
				s += b[i].c;
			}
		}
		cout << s << endl;
		for(int i = 1; i <= (s.size() + 1) / 2; i++){
			if(s[i] != s[s.size() - i + 1]){
				ans++;
				
			}
			cout << s[i] << " " << s[s.size() - i + 1] << endl;
		}
		cout << ans;
	}else{
		cout << maxn;
	}
	return 0;
}
