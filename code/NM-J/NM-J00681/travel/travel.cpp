#include<bits/stdc++.h>
using namespace std;
string lk1,s11,lk2,s22,a11;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>lk1>>s11>>lk2>>s22;
	if(lk1==lk2)a11='1';
	       else{cout<<"0000"<<endl;return 0;}
	if(s11[0]==s22[0]&&s11[1]==s22[1])a11+='1';
								else {cout<<"1000"<<endl;return 0;}
	if(s11[2]<='C'&&s22[2]<='C')a11+='1';
	else if(s11[2]>='D'&&s22[2]>='D')a11+='1';
	else{cout<<"1100"<<endl;return 0;}
	if((s11[2]=='A'&&s22[2]=='C')||(s22[2]=='A'&&s11[2]=='C')){cout<<"1110"<<endl;return 0;}
	else a11+='1';
	cout<<a11<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
