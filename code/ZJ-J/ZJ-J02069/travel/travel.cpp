#include<bits/stdc++.h>
using namespace std;
char c1[5],s1[5],c2[5],s2[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",c1,s1,c2,s2);
	if(!(c1[0]==c2[0]&&c1[1]==c2[1])){
		printf("0000");
		return 0;
	}
	printf("1");
	if(!(s1[0]==s2[0]&&s1[1]==s2[1])){
		printf("000");
		return 0;
	}
	printf("1");
	if(s1[2]>'C'&&s2[2]>'C') printf("11");
	else if(s1[2]<'D'&&s2[2]<'D') printf("1%d",(s1[2]<'C'&&s2[2]<'C')||(s1[2]>'A'&&s2[2]>'A'));
	else printf("00");
	return 0;
}