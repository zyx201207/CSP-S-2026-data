#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
string s;
long long a;
char c;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%ld", &a);
		cin >> c;
		for(int j = 1; j <= a; j++) s += c;
	}
	long long ans = 0;
	for(int i = 0; i <= (s.size() - 1) / 2; i++){
		if(s[i] != s[s.size() - 1 - i])
			ans++;
	}
	printf("%d", ans);
	return 0;
}

