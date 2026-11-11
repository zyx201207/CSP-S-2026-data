#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
bool flag1;
bool flag2;
void f(char a,char b){
	if(a=='A' && b=='B' || a=='B' && b=='A'){
		flag1=1;
		flag2=1;
	}
	else if(a=='A' && b=='C' || a=='C' && b=='A'){
		flag1=1;
	}
	else if(a=='B' && b=='C' || a=='C' && b=='B'){
		flag1=1;
		flag2=1;
	}
	else if(a=='D' && b=='F' || a=='F' && b=='D'){
		flag1=1;
		flag2=1;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			cout<<1;
			f(s1[2],s2[2]);
			if(flag1==1){
				cout<<1;
			}
			else{
				cout<<"00";
			}
			if(flag2==1){
				cout<<1;
			}
			else{
				cout<<"0";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}

