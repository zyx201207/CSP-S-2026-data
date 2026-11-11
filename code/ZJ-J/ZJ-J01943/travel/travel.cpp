#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int a,b;
bool ___(char c){
	if(c=='A'||c=='B'||c=='C')return 1;
	return 0;
}
bool _____(char c,char cc){
	if(c>cc)swap(c,cc);
	if(c=='A'&&cc=='B')return 1;
	if(c=='B'&&cc=='C')return 1;
	if(c=='D'&&cc=='F')return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s1>>b>>s2;
	if(a!=b){
		printf("0000");
		return 0;
	}
	else printf("1");
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		printf("000");
		return 0;
	}
	else printf("1");
	if(___(s1[2])^___(s2[2])){
		printf("00");
		return 0;
	}
	else printf("1");
	if(_____(s1[2],s2[2])){
		printf("1");
	}
	else printf("0");
}
/*
B站：@手撕根号二
洛谷：@mujunyan
我要上CSP迷惑行为大赏！！！！！
啊对，我一般会把思考过程打在注释里
我去了，感觉T2往后就有点难了啊
太神秘了
我去了，这个傻福Win7居然不支持运行框里复制吗？
10:26 请看T3
#1 in
02 01A 02 01B
#1 out
1111
#2 in
02 01C 02 01A
#2 out
1110
#3 in
02 01C 02 01D
#3 out
1100
#4 in
02 02B 02 01A
#4 out
1000
#5 in
02 01A 03 01A
#5 out
0000
*/
