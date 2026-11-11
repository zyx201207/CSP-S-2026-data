#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
bool ys1,ys2,ys3;
int main(){
	freopen("travel1.in","r",stdin);
	freopen("travel1.ans","w",stdout);
	freopen("travel2.in","r",stdin);
	freopen("travel2.ans","w",stdout);
	freopen("travel3.in","r",stdin);
	freopen("travel3.ans","w",stdout);
	freopen("travel4.in","r",stdin);
	freopen("travel4.ans","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		ys1=true;
	}
	else{
		cout<<0;
		ys1=false;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&ys1){
		cout<<1;
		ys2=true;
	}
	else{
		cout<<0;
		ys2=false;
	}
	if((('A'<=s1[2]<='C'&&'A'<=s2[2]<='C')||('D'<=s1[2]<='F'&&'D'<=s2[2]<='F'))&&ys1&&ys2){
		cout<<1;
		ys3=true;
	}
	else{
		cout<<0;
		ys3=false;
	}
	if(ys1&&ys2&&ys3&&(s1[2]+1==s2[2]||s2[2]+1==s1[2])){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
} 
