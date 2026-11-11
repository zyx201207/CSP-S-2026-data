#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool f=false;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		for(int i=0;i<2;i++){
			f=false;
			if(s1[i]==s2[i]){
				f=true;
			}
		}
		if(f==true){
			cout<<"1";
			if(s1[2]=='A'&&s2[2]=='B'){
				cout<<"11";
				return 0;
			}
			else if(s1[2]=='A'&&s2[2]=='C'){
				cout<<"10";
				return 0;
			}
			else if(s1[2]=='A'&&s2[2]!='C'){
				cout<<"00";
				return 0;
			}
			if(s1[2]=='B'&&s2[2]=='A'||s2[2]=='C'){
				cout<<"11";
				return 0;
			}
			else if(s1[2]=='B'&&s2[2]!='A'&&s2[2]!='C'){
				cout<<"00";
				return 0;
			}
			if(s1[2]=='C'&&s2[2]=='B'){
				cout<<"11";
				return 0;
			}
			else if(s1[2]=='C'&&s2[2]=='A'){
				cout<<"10";
				return 0;
			}
			else if(s1[2]=='C'&&s2[2]!='B'){
				cout<<"00";
				return 0;
			}
			if(s1[2]=='D'&&s1[2]=='E'){
				cout<<"11";
				return 0;
			}
			else if(s1[2]=='D'&&s1[2]=='E'){
				cout<<"00";
				return 0;
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
    return 0;
}
