#include<bits/stdc++.h>
using namespace std;
long long n, ans;
struct node{
	long long k;
	char c;
}s[200010];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%lld", &n);
	for(long long i = 1; i <= n; i++){
		scanf("%lld%s", &s[i].k, &s[i].c);
	}
	long long i = 1;
	while(i < n){
		long long t = min(s[i].k, s[n].k);
		if(s[i].c == s[n].c){
			s[i].k -= t;
			s[n].k -= t;
		}
		if(s[i].c != s[n].c){
			ans += t;
			s[i].k -= t;
			s[n].k -= t;
		}
		if(s[n].k == 0) n--;
		if(s[i].k == 0) i++;
	}
	printf("%lld", ans);
	return 0;
}
