#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main(){
	//取消注释 最后编译时间: 11:34:29-successful 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a1=s1[0]-'0'; //拆分数字s1 
	a1=a1*10+(s1[1]-'0');
	int a2=s2[0]-'0'; //拆分数字s2
	a2=a2*10+(s2[1]-'0');
	if(c1==c2){ //判断Q1 
		printf("1");
		if(a1==a2){ //判断Q2 
			printf("1");
			if( (s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C') || (s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F') ){ //判断Q3 
				printf("1");
				if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
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
