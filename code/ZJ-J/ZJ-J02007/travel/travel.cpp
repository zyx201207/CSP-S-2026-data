#include <bits/stdc++.h>
using namespace std;
bool chk[10]={0};
bool c3(char a,char b){
	if(a>='A'&&a<='C'&&b>='A'&&a<='C') return 1;
	if(a>='D'&&a<='F'&&b>='D'&&a<='F') return 1;
	return 0;
}
bool c4(char a,char b){
	if(a-b!=1) return 0;
	if(a=='D'&&b=='C') return 0;
	return 1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		chk[1]=1;
		if(s1.substr(0,2)==s2.substr(0,2)){
			if(s1<s2) swap(s1,s2);
			chk[2]=1;
			if(c3(s1[2],s2[2])){
				chk[3]=1;
				if(c4(s1[2],s2[2])) chk[4]=1;
			}
		}
	}
	for(int i=1;i<=4;i++) cout<<chk[i];
	return 0;
}
