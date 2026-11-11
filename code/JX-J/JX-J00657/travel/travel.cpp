#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	string st1=s1.substr(0,2),st2=s2.substr(0,2);
	if(st1==st2){
		cout<<1;
		if((s1[2]=='F'||s1[2]=='D')&&abs(int(s1[2]-s2[2]))==1){
			cout<<"11";
		}else if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='A'&&s2[2]=='C')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')){
			cout<<1;
			if((s1[2]=='B'&&s2[2]=='A')||(s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout<<"00";
		}
	}else{
		cout<<"000";
	}
	return 0;
}
