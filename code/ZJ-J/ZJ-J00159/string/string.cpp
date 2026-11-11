#include <bits/stdc++.h>
using namespace std;

long long n, a, ans=0;
char c;
string s;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	
	cin >> n;
	clock_t st = clock();
	for(int i=0; i<n; i++){
		cin >> a >> c;
		for(int j=1; j<=a; j++)	s += c;
	}
	long long len = s.size();

	
	for(int i=0; i<len/2; i++){
		if(s[i]!=s[len-i-1]) ans++;
	}

	cout << ans;
	return 0;
}
