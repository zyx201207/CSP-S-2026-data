#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	char s1[4],s2[4];
	scanf("%d",&c1);
	for(int i=1;i<=3;i++){
		cin>>s1[i];
	}
	scanf("%d",&c2);	
	for(int i=1;i<=3;i++){
		cin>>s2[i];
	}	
	if(c1==c2){
		printf("1");
		if(s1[1]==s2[1]&&s1[2]==s2[2]){
			printf("1");
			if((s1[3]=='A'||s1[3]=='B'||s1[3]=='C')&&(s2[3]=='A'||s2[3]=='B'||s2[3]=='C')){
				printf("1");
				if((s1[3]=='A'&&s2[3]=='B')||(s1[3]=='B'&&s2[3]=='A')){
					printf("1");
				}
				else if((s1[3]=='B'&&s2[3]=='C')||(s1[3]=='C'&&s2[3]=='B')){
					printf("1");
				}
				else{
					printf("0");
				}
			}
			else if((s1[3]=='D'||s1[3]=='F')&&(s2[3]=='D'||s2[3]=='F')){
				printf("11");
			}
			else{
				printf("00");
			}
	    }
	    else{
	    	printf("000");
		}
	}
	else{
		printf("0000");
	}
	return 0;
}
