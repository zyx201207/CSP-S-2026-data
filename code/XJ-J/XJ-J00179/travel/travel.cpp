#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
char c1[15],s1[15],c2[15],s2[15];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",c1+1,s1+1,c2+1,s2+1);
	if(c1[1]==c2[1]&&c1[2]==c2[2]){
		printf("1");
		if(s1[1]==s2[1]&&s1[2]==s2[2])
			printf("1");
		else{
			printf("000");
			return 0;
		}
		if(((s1[3]-'0')>=('A'-'0')&&(s1[3]-'0')<=('C'-'0'))&&((s2[3]-'0')>=('A'-'0')&&(s2[3]-'0')<=('C'-'0')))
			printf("1");
		else if((s1[3]=='D'||s1[3]=='F')&&(s2[3]=='F'||s2[3]=='D'))
			printf("1");
		else{
			printf("00");
			return 0;
		}
		if((s1[3]-'0'+1==s2[3]-'0'||s1[3]-'0'==s2[3]-'0'+1)){
			if((s1[3]=='D'&&s2[3]=='C')||(s1[3]=='C'&&s2[3]=='D')){
				printf("0");
				return 0;
			}
			else
				printf("1");
		}
		else
			printf("0");
		printf("\n");
	}
	else{
		printf("0000\n");
	}
	return 0;
}
