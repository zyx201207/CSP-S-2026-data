#include<bits/stdc++.h>
using namespace std;
string S1a,S1b,X1a,X1b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>S1a>>S1b>>X1a>>X1b;
	if(S1a==X1a){
		cout<<"1";
		if(S1b[0]==X1b[0] && S1b[1]==X1b[1]){
			cout<<"1";
			if((S1b[2]=='A'&&X1b[2]=='B') || (S1b[2]=='B'&&X1b[2]=='C') || (S1b[2]=='A'&&X1b[2]=='C') 
			|| (S1b[2]=='B'&&X1b[2]=='A') || (S1b[2]=='C'&&X1b[2]=='B') || (S1b[2]=='C'&&X1b[2]=='A') || (S1b[2]=='D'&&X1b[2]=='F') || (S1b[2]=='F'&&X1b[2]=='D')){
				cout<<"1";
				if((S1b[2]=='A'&&X1b[2]=='B') || (S1b[2]=='B'&&X1b[2]=='C')|| (S1b[2]=='B'&&X1b[2]=='A') || (S1b[2]=='C'&&X1b[2]=='B') || (S1b[2]=='F'&&X1b[2]=='D') || (S1b[2]=='D'&&X1b[2]=='F')){
					cout<<"1";
				}else{
					cout<<"0";
				}		
			}
			else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
