#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+1145;
char c;
int a;
int n;
string s = "1";
main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a;
		cin >> c;
		for(int j = 1;j <= a;j++){
			s=s+c;
		}
	}
	int ans = 0;
	for(int i = 1;i <= s.size()/2;i++){
		if(s[i]!=s[s.size()-i+1])ans++;
	}
	cout << ans << endl;
	return 0;
}
