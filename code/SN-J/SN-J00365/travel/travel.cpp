#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string s11,s21;
	char st1,st2;
	
	s11.push_back(s1[0]);
	s11.push_back(s1[1]);
	st1=s1[2];
	s21.push_back(s2[0]);
	s21.push_back(s2[1]);
	st2=s2[2];
	
	if(c1==c2){
		cout<<'1';
		if(s11==s21){
			cout<<'1';
			if(s11==s21 &&(
			(st1>='A'&&st1<='C'&&st2>='A'&&st2<='C')||
			((st1=='D'&&st2=='F')||(st1=='F'&&st2=='D'))
			)){
				cout<<'1';
				if(s11==s21 && 
				((st1=='A'&&st2=='B')||
				(st1=='B'&&(st2=='A'||st2=='C'))||
				(st1=='C'&&st2=='B')||
				(st1=='D'&&st2=='F')||
				(st1=='F'&&st2=='D')
				)
				)
				cout<<'1'<<endl;
				else cout<<'0'<<endl;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	
	
	
	
	return 0;
}
