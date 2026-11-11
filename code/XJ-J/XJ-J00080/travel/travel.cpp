#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string l1,l2;
char p1,p2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
    	cout<<"0000"<<endl;
    	return 0;
	}
    l1+=s1[0];
    l1+=s1[1];
    l2+=s2[0];
    l2+=s2[1];
    if(l1!=l2){
    	cout<<"1000"<<endl;
    	return 0;
	}
	p1=s1[2];
	p2=s2[2];
	if((p1=='D'&&p2=='F')||(p1=='F'&&p2=='D')){
		cout<<"1111";
		return 0;
	}
	if((p1=='A'&&p2=='B')||(p1=='B'&&p2=='A')){
		cout<<"1111";
		return 0;
	}
	if((p1=='C'&&p2=='B')||(p1=='B'&&p2=='C')){
		cout<<"1111";
		return 0;
	}
	if((p1=='A'&&p2=='F')||(p1=='F'&&p2=='A')){
		cout<<"1100";
		return 0;
	}
	if((p1=='A'&&p2=='D')||(p1=='D'&&p2=='A')){
		cout<<"1100";
		return 0;
	}
	if((p1=='B'&&p2=='F')||(p1=='F'&&p2=='B')){
		cout<<"1100";
		return 0;
	}
	if((p1=='B'&&p2=='D')||(p1=='D'&&p2=='B')){
		cout<<"1100";
		return 0;
	}
	if((p1=='C'&&p2=='F')||(p1=='F'&&p2=='C')){
		cout<<"1100";
		return 0;
	}
	if((p1=='C'&&p2=='D')||(p1=='D'&&p2=='C')){
		cout<<"1100";
		return 0;
	}
	cout<<"1110";
	return 0;
}


