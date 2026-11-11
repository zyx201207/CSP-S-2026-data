#include<bits/stdc++.h>
using namespace std;
string c1;
string z1;
string c2;
string z2;
string s;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int b=1;
	cin>>c1>>z1>>c2>>z2;
	if(c1==c2) s+='1';
	else {
		s+='0';
		s+='0';
		s+='0';
		s+='0';
		cout<<s;
		return 0;
	}
	for(int i=0;i<2;i++){
		if(z1[i]!=z2[i]) b=0;
	}
	if(b==1) {
		s+='1';	
		if((z1[2]<='C'&&z2[2]<='C')||(z1[2]>='D'&&z2[2]>='D')){
			s+='1';
			if(z1[2]+1==z2[2]||z1[2]-1==z2[2]){
				s+='1';
			}
			else s+='0';
		}
		else {
			s+='0';
			s+='0';
		}
	}
	else {
		s+='0';
		s+='0'; 
		s+='0';
	}
	cout<<s;
	return 0;
} 
