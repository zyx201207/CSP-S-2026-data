#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}else if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"11";
		char x=s1[2],y=s2[2];
		if(x=='A'&&y=='B'||x=='A'&&y=='C'||x=='B'&&y=='C'||x=='B'&&y=='A'||x=='C'&&y=='A'||x=='C'&&y=='B'||x=='D'&&y=='F'||x=='F'&&y=='D'){
			cout<<"1";
			if(x=='A'&&y=='B'||x=='B'&&y=='A'||x=='C'&&y=='B'||x=='B'&&y=='C'||x=='D'&&y=='F'||x=='F'&&y=='D'){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}
	}else{
		cout<<"1000";
	}
	return 0;
}
