#include<bits/stdc++.h>
using namespace std;
int calc1(char ch){
	if(ch=='A'||ch=='B'||ch=='C') return 1;
	return 2;
}
int calc2(char ch){
	if(ch=='A') return 1;
	if(ch=='B') return 2;
	if(ch=='C') return 3;
	if(ch=='D') return 5;
	return 6;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2; cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		putchar('1');
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			putchar('1');
			if(calc1(s1[2])==calc1(s2[2])){
				putchar('1');
				if(abs(calc2(s1[2])-calc2(s2[2]))<=1) puts("1");
				else puts("0");
			}
			else puts("00");
		}
		else puts("000");
	}
	else puts("0000");
	return 0;
}
