#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	ifstream cin("travel.in");
	ofstream cout("travel.out");
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		int h1=0,h2=0;
		string s=s1.substr(0,2);
		for(int i=0;i<s.size();i++){
			h1=h1*10+(s[i]-'0');
		}
		s=s2.substr(0,2);
		for(int i=0;i<s.size();i++){
			h2=h2*10+(s[i]-'0');
		}
		if(h1==h2){
			cout<<1;
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
				cout<<1;
				if(abs(int(s1[2]-s2[2]))==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
