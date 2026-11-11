#include<bits/stdc++.h>
using namespace std;
char a[100],b[100],c[100],d[100];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",a+1,b+1,c+1,d+1);
	int c1,s1,c2,s2,r1,r2;
	c1=(a[1]-'0')*10+(a[2]-'0');
	c2=(c[1]-'0')*10+(c[2]-'0');
	s1=(b[1]-'0')*10+(b[2]-'0');
	s2=(d[1]-'0')*10+(d[2]-'0');
	r1=b[3]-'A'+1;
	r2=d[3]-'A'+1;
	if(c1!=c2){
		printf("0000");
		return 0;
	}
	if(s1!=s2){
		printf("1000");
		return 0;
	}
	if((r1<4&&r2<4)||(r1>3&&r2>3)){
		if(abs(r1-r2)==1&&r1<4&&r2<4){
			printf("1111");
			return 0;
		}
		if((r1==4&&r2==6)||(r1==6&&r2==4)){
			printf("1111");
			return 0;
		}
		printf("1110");
		return 0;
	}
	else{
		printf("1100");
		return 0;
	}
	return 0;
}
