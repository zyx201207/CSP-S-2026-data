#include<bits/stdc++.h>
using namespace std;

bool jud(char a){
	if(a=='A'||a=='B'||a=='C') return 1;
	else return 0;
}

bool yes(char a,char b){
	if(a=='A'||a=='C'){
		if(b=='B') return 1;
		else return 0;
	}
	if(a=='B'){
		if(b=='A'||b=='C') return 1;
		else return 0;
	}
	if(a=='D'){
		return (b=='F');
	}
	return (b=='D');
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string str1,str2,num1,num2;
	cin>>num1>>str1>>num2>>str2;
	if(num1!=num2){
		cout<<"0000"<<"\n";
		return 0;
	}
	string j1=str1.substr(0,2);
	string j2=str2.substr(0,2);
	if(j1!=j2){
		cout<<"1000"<<"\n";
		return 0;
	}
	if(jud(str1[2])!=jud(str2[2])){
		cout<<"1100"<<"\n";
		return 0;
	}char ch=str1[2],ch1=str2[2];
	if(yes(ch,ch1)){
		cout<<"1111"<<"\n";
		return 0;
	}
	cout<<"1110"<<"\n";
	return 0;
}
