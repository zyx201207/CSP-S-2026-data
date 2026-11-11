#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
bool b1,b2,b3,b4;
bool cd1(char a,char b){
	if(a>b)swap(a,b);
	if(a==b)return false;
	if(a=='A'&&b=='B')return true;
	if(a=='A'&&b=='C')return true;
	if(a=='B'&&b=='C')return true;
	if(a=='D'&&b=='F')return true;
	return false;
}
bool cd2(char a,char b){
	if(a>b)swap(a,b);
	if(a==b)return false;
	if(a=='A'&&b=='B')return true;
	if(a=='B'&&b=='C')return true;
	if(a=='D'&&b=='F')return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)b1=1;
	else b1=0;
	if(b1&&s1[0]==s2[0]&&s1[1]==s2[1])b2=1;
	else b2=0;
	if(b2&&cd1(s1[2],s2[2]))b3=1;
	else b3=0;
	if(b3&&cd2(s1[2],s2[2]))b4=1;
	else b4=0;
	cout<<((b1==1)?1:0)<<((b2==1)?1:0)<<((b3==1)?1:0)<<((b4==1)?1:0);
	return 0;
}
