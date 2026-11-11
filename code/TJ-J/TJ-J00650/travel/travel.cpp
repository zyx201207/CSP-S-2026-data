#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2,s11,s21;
char s12,s22;
int main(){
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	 cin>>c1>>s1>>c2>>s2;
	 s11+=s1[0]+s1[1];
	 s12+=s1[2];

	 s21+=s2[0]+s2[1];
	 s22+=s2[2];
	 if(c1==c2){
	 	cout<<1;
	 	if(s11==s21){
	 		cout<<1;
	 		if('A'<=s12&&s12<='C'&&'A'<=s22&&s22<='C'||'D'<=s12&&s12<='E'&&'D'<=s22&&s22<='E'){
	 			cout<<1;
	 			if(abs((s12-'A')-(s22-'A'))==1&&(s12!='C'&&s22!='D')&&(s12!='D'&&s22!='C')){
	 				cout<<1;
				 }else{
				 	cout<<0;
				 }
			 }else{
			 	cout<<"00";
			 }
		 }else{
		 	cout<<"000";
		 }
	 }else{
	 	cout<<"0000";
	 }
    return 0;
}
