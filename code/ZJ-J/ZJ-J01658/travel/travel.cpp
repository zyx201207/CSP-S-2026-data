#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	char ll1=s1[2],ll2=s2[2];
	if(int(ll1)>int(ll2)){
		swap(ll1,ll2);
	}
	if((ll1=='A'&&ll2=='D')||(ll1=='A'&&ll2=='F')||(ll1=='B'&&ll2=='D')||(ll1=='B'&&ll2=='F')||(ll1=='C'&&ll2=='D')||(ll1=='C'&&ll2=='F')){
		cout<<0;
	}
	else{
		cout<<1;
	}
	if((ll1=='A'&&ll2=='B')||(ll1=='B'&&ll2=='C')||(ll1=='D'&&ll2=='F')){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
} 
