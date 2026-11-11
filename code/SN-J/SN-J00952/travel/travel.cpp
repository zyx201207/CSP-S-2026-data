#include<bits/stdc++.h>
#define ll long long
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		int z1,z2;
		char d1,d2;
		d1=s1[2];
		d2=s2[2];
		if(s1[0]=='0'){
			z1=s1[1]-'0';
		}
		else{
			z1=s1[1]-'0'+(s1[0]-'0')*10;
		}
		if(s2[0]=='0'){
			z2=s2[1]-'0';
		}
		else{
			z2=s2[1]-'0'+(s2[0]-'0')*10;
		}
		if(z1==z2){
			cout<<"1";
			if(d1=='F'&&d2=='D') cout<<"11";
			else if(d1=='D'&&d2=='F') cout<<"11";
			else if(d1=='A'&&d2=='B') cout<<"11";
			else if((d1=='B'&&d2=='C')||(d1=='B'&&d2=='A')) cout<<"11";
			else if(d1=='C'&&d2=='B') cout<<"11";
			else if(d1=='C'&&d2=='A') cout<<"10";
			else cout<<"00";
		}
		else cout<<"000";
	}
	else{
		cout<<"0000";
	}
	return 0;
}
