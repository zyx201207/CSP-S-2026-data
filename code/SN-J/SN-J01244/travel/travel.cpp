#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool is_down(char a){
	if(a=='A'||a=='B'||a=='C') return 1;
	else return 0;
}
bool is_up(char a){
	if(a=='D'||a=='F') return 1;
	else return 0;
}
int f(){
	cin>>c1>>s1>>c2>>s2;
	if(s2[2]>s1[2]) swap(s1[2],s2[2]);
	if(c1==c2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if((s1[0]==s2[0])&&(s1[1]==s2[1])) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((is_down(s1[2])&&is_down(s2[2]))||(is_up(s1[2])&&is_up(s2[2]))) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if((s1[2]=='F'&&s2[2]=='D')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A') ){
		cout<<1;
		return 0;
	}
	cout<<0;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	f();
	return 0;
}
