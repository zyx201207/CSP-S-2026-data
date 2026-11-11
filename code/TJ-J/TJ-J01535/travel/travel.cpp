#include<bits/stdc++.h>
using namespace std;
char s[40],cha,chb;
int ca,cb,la,lb;
int main(){
freopen("travel.in","r",stdin);	
freopen("travel.out","w",stdout);	
scanf("%s",s+1);

	ca=(s[1]-'0')*10+s[2]-'0';
	scanf("%s",s+1);
	la=(s[1]-'0')*10+s[2]-'0';
	cha=s[3];
	scanf("%s",s+1);
	cb=(s[1]-'0')*10+s[2]-'0';
	scanf("%s",s+1);
	lb=(s[1]-'0')*10+s[2]-'0';
	chb=s[3];
if(ca==cb){
	printf("%d",1);
}
else{
	printf("%d%d%d%d",0,0,0,0);
	return 0;
}
if(la==lb){
	printf("%d",1);
}
else{
	printf("%d%d%d",0,0,0);
	return 0;
}
	if(cha=='D'){
		if(chb=='F'){
			printf("%d%d",1,1);
			return 0;
		}
	}
	if(cha=='F'){
		if(chb=='D'){
			printf("%d%d",1,1);
			return 0;
		}
	}
	if(cha<='C'&&chb<='C'){
		printf("%d",1);
		if(cha=='B'||chb=='B'){
			printf("%d",1);
		}
		else{
			printf("%d",0);
		}
	}
	else{
		printf("%d%d",0,0);
	}
	
	
	return 0;
}
