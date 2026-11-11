#include<bits/stdc++.h>
using namespace std;

int main (){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,a2;
	string s1,s2;
	cin>>a1>>s1>>a2>>s2;
	if(a1==a2)cout<<"1";
	else {
		cout<<"0000";
		return 0;
	}
	int id1=0,id2=0;
	id1=(s1[0]-'0')*10+s1[1]-'0';
	id2=(s2[0]-'0')*10+s2[1]-'0';
//	cout<<id1<<" "<<id2;
	if(id1==id2)cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
		cout<<"1";
	}
	else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	if(s1[2]=='A'&&s2[2]=='B'){
		cout<<"1";
	}
	else if(s1[2]=='B'&&(s2[2]=='C'||s2[2]=='A')){
		cout<<"1";
	}
	else if(s1[2]=='C'&&s2[2]=='B'){
		cout<<"1";
	}
	else if(s1[2]=='D'&&s2[2]=='F'){
		cout<<"1";
	}
	else if(s1[2]=='F'&&s2[2]=='D'){
		cout<<"1";
	}
	else cout<<"0";
	return 0;
}

