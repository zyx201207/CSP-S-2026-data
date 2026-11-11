#include<bits/stdc++.h>
using namespace std;
char s[5][5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",&s[1],&s[2],&s[3],&s[4]);
	if(s[1][0]==s[3][0]&&s[1][1]==s[3][1]) printf("1");else{printf("0000");return 0;}
	if(s[2][0]==s[4][0]&&s[2][1]==s[4][1]) printf("1");else{printf("000");return 0;}
	if((s[2][2]>'C'&&s[4][2]>'C')||(s[2][2]<='C'&&s[4][2]<='C')) printf("1");else{printf("00");return 0;}
	if(abs(s[4][2]-s[2][2])==1) printf("1");else{printf("0");return 0;}
	return 0;
}
// I love CCF best!!!