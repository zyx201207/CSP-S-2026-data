#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 1;
inline int read(){
	int f = 1,x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9'){
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return f * x;
}
int n,l,r;
long long ans;
struct String{
	char c;
	int ai;
}s[MAXN];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n = read();
	for (int i = 1; i <= n; i++){
		s[i].ai = read();
		s[i].c = getchar();
		getchar();
	}
	l = 1,r = n;
	while (l <= r){
		if (s[l].c == s[r].c){
			if (s[l].ai == s[r].ai){
				l++,r--;
			}else if (s[l].ai < s[r].ai){
				s[r].ai -= s[l].ai;
				l++;
			}else{
				s[l].ai -= s[r].ai;
				r--;
			}
		}else{
			if (s[l].ai == s[r].ai){
				ans += s[l].ai;
				l++,r--; 
			}
			else if (s[l].ai < s[r].ai){
				ans += s[l].ai;
				s[r].ai -= s[l].ai;
				l++;
			}else{
				ans += s[r].ai;
				s[l].ai -= s[r].ai;
				r--;
			}
		}
	}
	printf("%lld\n",ans); 
	return 0;
}
