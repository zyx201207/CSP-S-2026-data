#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool l1,l2;//T=过道左侧（ABC），F=过道右侧（DE）
int m1,m2;
int check1(char x){
	if(x=='A')return 1;
	if(x=='B')return 2;
	if(x=='C')return 3;
	if(x=='D')return 4;
	if(x=='F')return 5;
}
bool check2(char x){
	if(x=='A')return 1;
	if(x=='B')return 1;
	if(x=='C')return 1;
	if(x=='D')return 0;
	if(x=='F')return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2)cout << "1";//两张车票对应的座位是否在同一节车厢
	else cout << "0";
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1])cout << "1";//两张车票对应的座位是否在同一节车厢的同一排
	else cout << "0";
	//if(s1[3]=='A'||s1[3]=='B'||s1[3]=='C')l1=true;
	//if(s2[3]=='A'||s2[3]=='B'||s2[3]=='C')l2=true;
	//if(s1[3]=='D'||s1[3]=='E')l1=false;
	//if(s2[3]=='D'||s2[3]=='E')l2=false;
	l1=check2(s1[2]);
	l2=check2(s2[2]);
	m1=check1(s1[2]);
	m2=check1(s2[2]);
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&l1==l2)cout << "1";//两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧
	else cout << "0";
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&l1==l2&&(m1==m2+1||m1==m2-1))cout << "1";//两张车票对应的座位是否相邻 
	else cout << "0";
	return 0;
}
