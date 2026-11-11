#include<bits/stdc++.h>
using namespace std;
char c1[5],c2[5],s1[5],s2[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",c1+1,c2+1,s1+1,s2+1);
	if(c1[1]!=s1[1]||c1[2]!=s1[2]){
		printf("0000");
	}else{
		printf("1");
		if(c2[1]!=s2[1]||c2[2]!=s2[2]){
			printf("000");
		}else{
			printf("1");
			if((c2[3]<='C'&&s2[3]<='C')||(c2[3]>'C'&&s2[3]>'C')){
				printf("1");
				if(((c2[3]<='C'&&s2[3]<='C')&&max(c2[3],s2[3])-min(c2[3],s2[3])==1)||(c2[3]>'C'&&s2[3]>'C')){
					printf("1");
				}else{
					printf("0");
				}
			}else{
				printf("00");
			}
		}
	}
	return 0;
}