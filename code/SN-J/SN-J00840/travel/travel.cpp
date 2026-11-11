//SN-J00840 谢俊哲 西安交通大学附属中学 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;//cin<<   cout>> 骗到你了？ 名字遮一下 
	//我要上迷惑行为大赏 
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		printf("1");
	}else{
		printf("0000\n");
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		printf("1");
	}else{
		printf("000\n");
		return 0;
	}
	if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='E')&&(s2[2]=='D'||s2[2]=='E'))){
		printf("1");
	}else{
		printf("00\n");
		return 0;
	}
	if((s1[2]=='A'&&s2[2]=='B')||(s2[2]=='A'&&s1[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s2[2]=='B'&&s1[2]=='C')||(s1[2]=='D'&&s2[2]=='F')||(s2[2]=='D'&&s1[2]=='F')){
		printf("1\n");
		return 0;
	}else{
		printf("0\n");
		return 0;
	}
	return 0;
}
