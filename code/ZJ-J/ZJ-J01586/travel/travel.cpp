#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
bool check1(string c1,string c2){
	char a=c1[0],b=c1[1],c=c2[0],d=c2[1];
	if(a==c&&b==d) return 0;
	else return 1;
}
bool check2(string c1,string c2){
	char a=c1[2],b=c2[2];
	if(a<='C'&&b<='C'||a>='D'&&b>='D') return 0;
	else return 1;
}
bool check3(string c1,string c2){
	int a=c1[2],b=c2[2];
	if(abs(a-b)==1) return 0;
	else return 1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3) cout<<"0000";
	else if(check1(s2,s4)) cout<<"1000";
	else if(check2(s2,s4)) cout<<"1100";
	else if(check3(s2,s4)) cout<<"1110";
	else cout<<"1111";
	return 0;
}