#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	char s1[5],s2[5];
	cin>>c1;
	for(int i=1;i<=3;i++){
		cin>>s1[i];
	}
	cin>>c2;
	for(int i=1;i<=3;i++){
		cin>>s2[i];
	}
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<"1";
		if(s1[1]!=s2[1]||s1[2]!=s2[2]){
			cout<<"000";
			return 0;
		}
		else{
			cout<<"1";
			if(s1[3]=='A'&&s2[3]=='D'||s1[3]=='A'&&s2[3]=='E'||s1[3]=='B'&&s2[3]=='D'||s1[3]=='B'&&s2[3]=='E'||s1[3]=='C'&&s2[3]=='D'||s1[3]=='C'&&s2[3]=='E'||s2[3]=='A'&&s1[3]=='D'||s2[3]=='A'&&s1[3]=='E'||s2[3]=='B'&&s1[3]=='D'||s2[3]=='B'&&s1[3]=='E'||s2[3]=='C'&&s1[3]=='D'||s2[3]=='C'&&s1[3]=='E'){
				cout<<"00";
				return 0;
			}
			else{
				cout<<"1";
				if(s1[3]=='A'&&s2[3]=='B'||s1[3]=='B'&&s2[3]=='C'||s1[3]=='D'&&s2[3]=='E'||s2[3]=='A'&&s1[3]=='B'||s2[3]=='B'&&s1[3]=='C'||s2[3]=='D'&&s1[3]=='E'){
					cout<<"1";
					return 0;
				}
				else{
					cout<<"0";
					return 0;
				}
			}
		}
	}
	return 0;
} 
