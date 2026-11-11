#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string s="0000";
int t(char x){
	if(x=='A' || x=='B' || x=='C') return 1;
	if(x=='D' || x=='F') return 2;
}
bool l(char x,char y){
	if((x=='A' || x=='B' || x=='C') &&(y=='A' || y=='B' || y=='C') &&(x-y==1 || x-y==-1))return 1;
	else if(x=='D' && y=='F' || x=='F' && y=='D') return 1;
	else return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) s[0]='1';//是否在同一节车厢;
	if(s1[0]==s2[0] && s1[1]==s2[1]){//是否在同一节车厢的同一排;
		s[1]='1';
	}
	if(t(s1[2])==t(s2[2]) && s[1]=='1'){
		s[2]='1';//是否在同一节车厢的同一排且在同一侧;
	}
	if(l(s1[2],s2[2]))  s[3]='1';
	cout<<s;
	return 0;
}
