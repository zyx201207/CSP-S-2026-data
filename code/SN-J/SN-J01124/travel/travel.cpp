#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<1000;
		return 0;
	}
	char r=s1[2],x=s2[2];
	if(r=='A'){
		if(x=='B'){
			cout<<1111;
		}
		else if(x=='C'){
			cout<<1110;
		}
		else{
			cout<<1100;
		}
	}
	else if(r=='B'){
		if(x=='A'||x=='C'){
			cout<<1111;
		}
		else{
			cout<<1100;
		}
	}
	else if(r=='C'){
		if(x=='B'){
			cout<<1111;
		}
		else if(x=='A'){
			cout<<1110;
		}
		else{
			cout<<1100;
		}
	}
	if(r=='D'){
		if(x=='F'){
			cout<<1111;
		}
		else{
			cout<<1100;
		}
	}
	if(r=='F'){
		if(x=='D'){
			cout<<1111;
		}
		else{
			cout<<1100;
		}
	}
	return 0;
}
