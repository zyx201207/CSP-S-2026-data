#include<bits/stdc++.h>
using namespace std;
char a[100];
char b[100];
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	int q,w,e,r;
	scanf("%c%c%c%c",&a[1],&a[2],&b[1],&b[2]);
	if(a[1]==b[1]){
			q=1;
	}
	else{
		printf("0000");
		return 0;
	}
	for(int i=1;i<2;i++){
		if(a[2]/10==b[2]/10){
			w=1;
		}	
		else{
			printf("1000");
			return 0;
		}
		if(a[2]%10-'A'<'D'-'A'&&b[2]%10-'A'<'D'-'A'||a[2]%10-'A'=='D'-'A'&&b[2]%10-'A'=='D'-'A'){
			e=1;
		}
		else{
			printf("1100");
			return 0;
		}
		if('a[2]%10'-'b[2]%10'==1||'b[2]%10'-'a[2]%10'==1){
			r=1;
		}
		else{
			printf("1110");
			return 0;
		}
	}
	printf("%d%d%d%d",q,w,e,r);
	return 0;
} 
