#include<bits/stdc++.h>
using namespace std;
char a[5],b[5];
bool lp;
int a1,b1,a2,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%s%d%s",&a1,a,&b1,b);//¹Èelzjchh ÎªPCLÄ¬°§ 
	if(a1!=b1){
		printf("0000");
		return 0;
	}
	printf("1");
	a2=(a[0]-'0')*10+a[1]-'0';
	b2=(b[0]-'0')*10+b[1]-'0';
	a[0]=a[2],b[0]=b[2];
	if(a2!=b2){
		printf("000");
		return 0;
	}
	printf("1");
	if(!((a[0]=='A'&&(b[0]=='B'||b[0]=='C'))||(a[0]=='B'&&(b[0]=='A'||b[0]=='C'))||(a[0]=='C'&&(b[0]=='A'||b[0]=='B'))||(a[0]=='D'&&b[0]=='F')||(a[0]=='F'&&b[0]=='D'))){
		printf("00");
		return 0;
	}
	printf("1");
	if(!((a[0]=='A'&&b[0]=='B')||(a[0]=='B'&&(b[0]=='A'||b[0]=='C'))||(a[0]=='C'&&b[0]=='B')||(a[0]=='D'&&b[0]=='F')||(a[0]=='F'&&b[0]=='D'))){
		printf("0");
		return 0;
	}
	printf("1");
	return 0;
}
