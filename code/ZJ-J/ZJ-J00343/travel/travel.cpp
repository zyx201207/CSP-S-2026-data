#include<bits/stdc++.h>
using namespace std;
bool f(char s1,char s2){
	if(s1=='D') s1='E';
	if(s2=='D') s2='E';
	int a=s1-s2;
	return a==1||a==-1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	cout<<(c1==c2)<<(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1])
		<<(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&((s1[2]<='C')==(s2[2]<='C')))
		<<(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&((s1[2]<='C')==(s2[2]<='C'))&&f(s1[2],s2[2]));
	return 0;
}