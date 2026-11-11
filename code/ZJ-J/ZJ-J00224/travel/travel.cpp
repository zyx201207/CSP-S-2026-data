#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1[4],s2[4],c1[3],c2[3];
	scanf("%s%s %s%s%s %s%s %s%s%s",&c1[1],&c1[2],&s1[1],&s1[2],&s1[3],&c2[1],&c2[2],&s2[1],&s2[2],&s2[3]);
	if(c1[1]==c2[1]&&c1[2]==c2[2]){
		printf("1");
		if(s1[1]==s2[1]&&s2[2]==s1[2]){
			printf("1");
			if(((s1[3]=="A"||s1[3]=="B"||s1[3]=="C")&&(s2[3]=="A"||s2[3]=="B"||s2[3]=="C"))||((s1[3]=="D"||s1[3]=="F")&&(s2[3]=="D"||s2[3]=="F"))){
				printf("1");
				if((s1[3]=="A"&&s2[3]=="B")||(s1[3]=="B"&&s2[3]=="C")||(s1[3]=="D"&&s2[3]=="F")||(s2[3]=="A"&&s1[3]=="B")||(s2[3]=="B"&&s1[3]=="C")||(s2[3]=="D"&&s1[3]=="F")){
					printf("1");
				}else{
					printf("0");
				}
			}else{
				printf("00");	
			}
		}else{
			printf("000");
		}
	}else{
		printf("0000");
	}
	return 0;
}