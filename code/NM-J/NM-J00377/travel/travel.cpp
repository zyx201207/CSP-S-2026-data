#include <bits/stdc++.h>
using namespace std;

char c1[10],s1[10],c2[10],s2[10];
int a = 0,b = 0;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",c1+1,s1+1,c2+1,s2+1);
	if(c1[1] == c2[1] && c1[2] == c2[2]){
		printf("1");
	}else{
		printf("0000");
		return 0;
	}
	a = (s1[1] - '0') * 10 + (s1[2] - '0');
	b = (s2[1] - '0') * 10 + (s2[2] - '0');
	if(a == b){
		printf("1");
	}else{
		printf("000");
		return 0;
	}
	if((s1[3] == 'A' || s1[3] == 'B' || s1[3] == 'C') && (s2[3] == 'D' || s2[3] == 'F')){
		printf("00");
		return 0;
	}
	if((s2[3] == 'A' || s2[3] == 'B' || s2[3] == 'C') && (s1[3] == 'D' || s1[3] == 'F')){
		printf("00");
		return 0;
	}
	printf("1");
	if(s1[3] - 1 == s2[3] || s1[3] + 1 == s2[3])
		printf("1");
	else{
		printf("0");
		return 0;
	}
	return 0;
}
