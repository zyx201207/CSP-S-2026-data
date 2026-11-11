#include <bits/stdc++.h>

using namespace std;
string c1,s1,c2,s2;
bool in_same,can,could,cd;
int main(){
	freopen("travel.in","r",stdin);
	freoepn("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		in_same=0;
		cout<<"0";
	}
	else {
		in_same=1;
		cout<<"1";
	}
	int a1,a2;
	a1=s1.size()-2;
	a2=s2.size()-2;
	can=true;
	if(in_same){
		for(int i=0;i<a1;i++){
			if(s1[i]!=s2[i]){
				can=false;
				cout<<"0";
				break;
			}
		}
		if(can){
			cout<<"1";
		}
	}
	else {
		cout<<"0";
		can=false;
	}
	int n=a1+1,m=a2+1;
	if(in_same&&can){
		if((s1[n]>='D'&&s1[n]<='F'&&s2[n]>='A'&&s2[n]<='C')||(s2[n]>='D'&&s2[n]<='F'&&s1[n]>='A'&&s1[n]<='C')){
			cout<<"0";
			could=false;
		}
		else {
			cout<<"1";
			could=true;
		}
	}
	else {
		cout<<"0";
		could=false;
	}
	if(in_same&&can&&could){
		if(s1[n]==s2[n]-1||s2[n]==s1[n]-1){
			cout<<"1";
		}
		else {
			cout<<"0";
		}
	}
	else {
		cout<<"0";
	}
	cout<<"\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
