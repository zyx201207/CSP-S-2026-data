#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#define debug printf
#else
int debug(...){return 0;}
#endif
string c1,s1,c2,s2;
// C-car, S-seat
char side[] = "111222";
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
#ifndef LOCAL
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
#endif
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		puts("0000");
		return 0;
	}
	putchar('1');
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		puts("000");
		return 0;
	}
	putchar('1');
	if(side[s1[2]-'A']!=side[s2[2]-'A']){
		puts("00");
		return 0;
	}
	putchar('1');
	if(abs(s1[2]-s2[2])!=1&&side[s1[2]-'A']!='2'){
		putchar('0');
		return 0;
	}
	putchar('1');
	return 0;
}
