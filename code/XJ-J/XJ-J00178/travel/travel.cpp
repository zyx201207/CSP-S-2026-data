#include<bits/stdc++.h>
using namespace std;
string a1,a2;
int c1,c2;
int main(){
	preopen("tavel.in","r",stdin);
	preopen("travel.out","w",stdout);
	cin>>c1>>a1>>c2>>a2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}if(a1[0]==a2[0]&&a1[1]==a2[1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}if((a1[2]=='A'&&a2[2]=='B')||(a1[2]=='B'&&a2[2]=='A')||(a1[2]=='A'&&a2[2]=='C')||(a1[2]=='C'&&a2[2]=='A')||(a1[2]=='C'&&a2[2]=='B')||(a1[2]=='B'&&a2[2]=='C')||(a1[2]=='D'&&a2[2]=='F')||(a1[2]=='F'&&a2[2]=='D')){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}if((a1[2]=='A'&&a2[2]=='B')||(a1[2]=='B'&&a2[2]=='A')||(a1[2]=='B'&&a2[2]=='C')||(a1[2]=='C'&&a2[2]=='B')||(a1[2]=='C'&&a2[2]=='D')||(a1[2]=='D'&&a2[2]=='C')||(a1[2]=='D'&&a2[2]=='F')||(a1[2]=='F'&&a2[2]=='D')){
		cout<<"1";
	}else{
		cout<<"0";
	}return 0;
} 
