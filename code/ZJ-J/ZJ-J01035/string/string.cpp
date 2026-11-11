#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
int n, ans;
string s;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	long long len = 0;
	for(int i = 1;i <= n;i ++){
		int a;
		char c;
		scanf("%d %c", &a, &c);
		len += a;
		for(int i = 1;i <= a;i ++){
			s += c;
		}
	}
	string d = s[0] + s.substr(0, len / 2), a = d;
	reverse(a.begin(), a.end());
	if(len % 2 == 0){
		d += a;
	}
	else{
		d += s[len / 2 + 1] + a;
	}
	for(int i = 0;i < len;i ++){
		if(d[i] != s[i]){
			ans ++;
		}
	}
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}