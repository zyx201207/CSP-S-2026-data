#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string sa,sc;
	int ca,cc;
	cin>>ca>>sa>>cc>>sc;
	if(ca==cc&&ca<18&&cc<18&&ca>0&&cc>0){
		cout<<"1";
	}else{
		cout<<"0";
	}
	
	int a,c;
	a=(sa[0]-48)*10+sa[1]-48;
	c=(sc[0]-48)*10+sc[1]-48;
	if(a==c&&a>0&&a<19){
		cout<<"1";
	}else{
		cout<<"0";
	}
	
	char ta,tc;
	ta=sa[2];
	tc=sc[2];
	if(ta>='A'&&ta<='C'&&tc>='A'&&tc<='C'){
		cout<<"1";
	}else if(ta>='A'&&ta<='C'&&tc>='D'&&tc<='F'){
		cout<<"0";
	}else if(ta>='D'&&ta<='F'&&tc>='A'&&tc<='C'){
		cout<<"0";
	}else if(ta>='D'&&ta<='F'&&tc>='D'&&tc<='F'){
		cout<<"1";
	}
	
	if((ta=='A'&&tc=='B')||(tc=='A'&&ta=='B')){
		cout<<"1";
	}else if((ta=='C'&&tc=='B')||(tc=='B'&&ta=='C')){
		cout<<"1";
	}else if((ta=='F'&&tc=='D')||(tc=='D'&&ta=='F')){
		cout<<"1";
	}else {
		cout<<"0";
	}
	return 0;
}