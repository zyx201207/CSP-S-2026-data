#include<iostream>
#include<cstdio>

using namespace std;
int seat[6]={1,2,3,1,0,2};
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	
	if(c1!=c2){
		cout<<"0000"<<endl;
		return 0;
	}
	
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"1000"<<endl;
		return 0;
	}
	
	if((s1[2]<='C'&&s2[2]>='D') || (s1[2]>='D'&&s2[2]<='C')){
		cout<<"1100"<<endl;
		return 0;
	}
	
	if(seat[s1[2]-'A']-seat[s2[2]-'A']==1 || seat[s2[2]-'A']-seat[s1[2]-'A']==1){
		cout<<"1111"<<endl;
		return 0;
	}
	else {
		cout<<"1110"<<endl;
		return 0;
	}
	
}
