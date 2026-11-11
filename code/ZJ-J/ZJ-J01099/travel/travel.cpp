#include<bits/stdc++.h>
using namespace std;
char C_1[5],S_1[5],C_2[5],S_2[5];
char gt(){
	char ch=getchar();
	while(ch<'0'&&ch>'9'&&ch<'A'&&ch>'F'||ch==' ')ch=getchar();
	return ch;
}
int gtp(char a){
	if(a=='A'||a=='B'||a=='C')return 1;
	else return 2;
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
//	for(int i=1;i<=10;i++)cout<<gt();
	C_1[0]=gt(),C_1[1]=gt(),S_1[0]=gt(),S_1[1]=gt(),S_1[2]=gt();
	C_2[0]=gt(),C_2[1]=gt(),S_2[0]=gt(),S_2[1]=gt(),S_2[2]=gt();
	if(S_1[2]=='F')S_1[2]='E';
	if(S_2[2]=='F')S_2[2]='E';
	if(C_1[0]!=C_2[0]||C_1[1]!=C_2[1]){
		printf("0000");
	}else if(S_1[0]!=S_2[0]||S_1[1]!=S_2[1]){
		printf("1000");
	}else if(gtp(S_1[2])!=gtp(S_2[2])){
		printf("1100");
	}else if(int(S_2[2]-S_1[2])!=1&&int(S_1[2]-S_2[2])!=1){
		printf("1110");
	}else{
		printf("1111");
	}
	return 0;
}