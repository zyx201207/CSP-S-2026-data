#include<bits/stdc++.h>
using namespace std;

long long n;
string s,s1;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i ++){
		long long a;
		char c;
		cin >> a >> c;
		for(long long j = 1; j <= a; j ++){
			s += c;
		}
	}
	long long l = s.length();
	for(int i = 1; i <= l; i ++){
		s1[i] = s[i - 1];
	}
	long long ans = 0;
	for(long long i = 1; i <= l / 2 + 1; i ++){
			if(s1[i] != s1[l + 1 - i]) ans ++;
	}
	cout << ans;
	return 0;
} 

