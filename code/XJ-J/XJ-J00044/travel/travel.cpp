#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2;
	int a1,a2;
	bool b1=0,b2=0,b3=0,b4=0;
	cin>>a1>>s1>>a2>>s2;
	if(a1==a2){
		b1=1;
	}else{
		b1=0;
	}
	
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]!=s2[2]){
		b2=1;
	}else{
		b2=0;
	}
	
	if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='C'&&s2[2]=='A')||(s1[2]=='A'&&s2[2]=='C')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')&&(s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]!=s2[2])){
		if(s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]!=s2[2]){
			b3=1;
		}
	}else{
		b3=0;
	}
	
	if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
		if(s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]!=s2[2]){
			b4=1;
		}
	}else{
		b4=0;
	}
	
	if(b1){
		cout<<"1";
	}else{
		cout<<"0";
	}

	if(b2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	
	if(b3){
		cout<<"1";
	}else{
		cout<<"0";
	}
	
	if(b4){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}

