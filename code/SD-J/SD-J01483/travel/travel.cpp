#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<"1";
	}
	string l1,l2;
	l2+=s2[0]+s2[1];
	l1+=s1[0]+s1[1];
	char w1=s1[2],w2=s2[2];
	if(l1!=l2){
		cout<<"000";
		return 0;
	}
	else{
		cout<<"1";
	}
	if((w1<='C'&&w2<='C')||(w1>='D'||w1>='D')){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	if(abs((int)w1-(int)w2)==1){
		cout<<"1";
	}
	else{
		cout<<"0";
		return 0;
	}
	return 0;
}
