#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n;
	string s;
	cin >> n;
	for (long long i = 1; i <= n; i++){
		long long x; char c;
		cin >> x >> c;
		for (long long j = 1; j <= x; j++){
			s += c;
		}
	} 
	
	long long lft = 0, rgt = s.size() - 1;
	long long ans = 0;
	while (lft < rgt){
		if (s[lft] != s[rgt]){
			ans++;
		}
		lft++, rgt--;
	}
	cout << ans << endl;
	return 0;
}
