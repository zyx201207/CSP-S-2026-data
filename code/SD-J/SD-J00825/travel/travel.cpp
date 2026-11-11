#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	int x=(s1[0]-'0')*10+s1[1]-'0' , y=(s2[0]-'0')*10+s2[1]-'0';
	if(x==y){
		cout<<1;
	}
	else{
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	bool l1,l2;
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
		l1=true;
	}
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
		l2=true;
	}
	if(l1==l2){
		cout<<1;
		if(l1==false){
			cout<<1;
		}
		else{
			bool ifa,ifc;
			if(s1[2]=='A'||s2[2]=='A'){
				ifa=true;
			}
			if(s1[2]=='C'||s2[2]=='C'){
				ifa=true;
			}
			if(ifa==ifc&&ifa==true){
				cout<<0;
			}
			else{
				cout<<1;
			}
		}
	}
	else{
		cout<<0;
		cout<<0;
		return 0;
	}
	return 0;
}
