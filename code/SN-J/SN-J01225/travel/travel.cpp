#include <bits/stdc++.h>
using namespace std;
int c1,c2;
int p1=0,p2=0,p3=0;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	//1
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0000;
		p1=1;
	}
	//2
	if((s1[0]==s2[0]) && (s1[1]==s2[1]) && (p1==0)){
		cout<<1;
	}else{
		cout<<000;
		p2=1;
	}
	//3
	if(((s1[2]=='F' && s2[2]=='D')||(s1[2]=='D' && s2[2]=='F')) && (p1==0) && (p2==0)){
		cout<<1;
	}else{
		if((s1[2]=='A'||'B'||'C') && (s2[2]=='A'||'B'||'C') && (p1==0) && (p2==0)){
			cout<<1;
		}else{
			p3=1;
			cout<<00;
		}
	}
	//4
	if(((s1[2]=='A'&&s2[2]=='B') || (s1[2]=='B'&&s2[2]=='C') || (s1[2]=='B'&&s2[2]=='A') || (s1[2]=='C'&&s2[2]=='B') || (s1[2]=='F' && s2[2]=='D') || (s1[2]=='D' && s2[2]=='F')) && (p1==0) && (p2==0) && (p3==0)){
		cout<<1;
	}else{
		cout<<0;
	}	
	return 0;
}
