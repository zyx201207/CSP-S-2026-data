#include<bits/stdc++.h>
using namespace std;
char c[35],s[35],cc[35],ss[35];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",c+1,s+1,cc+1,ss+1);
	for(int i=1;i<=2;i++){
		if(c[i]!=cc[i]){
			printf("0000\n");
			return 0;
		}
	}
	printf("1");
	for(int i=1;i<=2;i++){
		if(s[i]!=ss[i]){
			printf("000\n");
			return 0;
		}
	}
	printf("1");
	if((s[3]<='C'&&ss[3]>='D')||(s[3]>='D'&&ss[3]<='C')){
		printf("00\n");
		return 0;
	}else{
		printf("1");
	}
	if(s[3]==ss[3]+1||ss[3]==s[3]+1){
		printf("1\n");
	}else{
		printf("0\n");
	}
	return 0;
}
