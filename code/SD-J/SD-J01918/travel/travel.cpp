#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	string pai1="";
	pai1+=s1[0];
	pai1+=s1[1];
	string pai2="";
	pai2+=s2[0];
	pai2+=s2[1];
	if(pai1!=pai2){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	char ce1=s1[2];
	char ce2=s2[2];
	if(ce1>='A' and ce1<='C' and ce2>='A' and ce2<='C'){
		cout<<"1";
		bool aa=false,bb=false,cc=false;
		if(ce1=='A' or ce2=='A') aa=true;
		if(ce1=='B' or ce2=='B') bb=true;
		if(ce1=='C' or ce2=='C') cc=true;
		if((aa and bb) or (bb and cc)){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	else if(ce1>='D' and ce1<='E' and ce2>='D' and ce2<='E'){
		cout<<"11";
	}
	else{
		cout<<"00";
	}
	return 0;
} 
