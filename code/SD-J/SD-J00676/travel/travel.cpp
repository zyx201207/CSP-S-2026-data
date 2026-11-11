#include<bits/stdc++.h>
using namespace std;
string c1,c2;
string s1,s2;
bool check(char x,char y){
	if(y>x) swap(x,y);
	if(x-y==1) return true;
	if(x=='F'&&y=='D') return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	string p1=s1.substr(0,2);
	string p2=s2.substr(0,2);
	if(c1==c2){
		if(p1==p2){
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
				if(check(s1[2],s2[2])) {cout<<"1111";return 0;}
				else {cout<<"1110";return 0;}
			}else {cout<<"1100";return 0;}
		}else {cout<<"1000";return 0;}
	}else {cout<<"0000";return 0;}
	return 0;
}

