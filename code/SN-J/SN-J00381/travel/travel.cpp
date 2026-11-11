#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string a1="",a2="";
	char b1,b2;
	if(c1==c2){
		cout<<"1";
	}
	else {
		cout<<"0000";return 0;
	}
	for(int i=0;i<2;i++){
		a1+=s1[i];a2+=s2[i];
	}
	if(a1==a2){
		cout<<"1";
	}
	else {
		cout<<"000";return 0;
	}
	for(int i=0;i<2;i++){
		if(i=2){
			b1=s1[2];b2=s2[2];
			}
		}
	if(b1=='A'||b1=='B'||b1=='C'){
		if((b2=='A'||b2=='B'||b2=='C')&&b2!=b1){
			cout<<"1";
			if(b1+1==b2||b1-1==b2){
				cout<<"1";
				return 0;
			}
			else cout<<"0";
		}
		else cout<<"00";
	}
	 if(b1=='D'||b1=='F'){
		if((b2=='D'||b2=='F')&&b2!=b1){
			cout<<"11";return 0;
		}
		else cout<<"00";
	}
	
	
	return 0;
}
