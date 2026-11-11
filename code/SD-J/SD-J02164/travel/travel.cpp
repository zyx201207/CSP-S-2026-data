#include<bits/stdc++.h>

using namespace std;

char c1[5],c2[5],c3[5],c4[5];
string s1,s2,s3,s4;


int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s %s %s %s",c1,c2,c3,c4);
	s1+=c1;
	s2+=c2;
	s3+=c3;
	s4+=c4;
	int n1=s2[2]-'A'+1,n2=s4[2]-'A'+1;
	if(s1==s3){
		printf("1");
		if(s2[0]==s4[0]&&s2[1]==s4[1]){
			printf("1");
			if(n1<=3&&n2<=3||n1>=4&&n2>=4){
				printf("1");
				if(abs(n1-n2)==1){
					printf("1");
				}else printf("0");
			}else printf("00");
		}else printf("000");
	}else printf("0000");
	
	return 0;
} 
