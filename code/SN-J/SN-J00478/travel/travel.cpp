#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string c,s,C,S;
	cin>>c>>s>>C>>S;
	if(c==C){
		cout<<"1";
		if(s[0]==S[0]){
			if(s[1]==S[1]){
				cout<<"1";
				if(s[2]=='D'&&S[2]=='F' || s[2]=='F'&&S[2]=='D') cout<<"1"<<"1";
				else if(s[2]=='A'&&S[2]=='B' || s[2]=='B'&&S[2]=='A'){
					cout<<"1";
					if(s[2]=='D'&&S[2]=='F' || s[2]=='F'&&S[2]=='D') cout<<"1";
					else if(s[2]=='A'&&S[2]=='B' || s[2]=='B'&&S[2]=='A') cout<<"1";
					else if(s[2]=='B'&&S[2]=='C' || s[2]=='C'&&S[2]=='B') cout<<"1";
					else cout<<"0";	
				} 
				else if(s[2]=='B'&&S[2]=='C' || s[2]=='C'&&S[2]=='B'){
					cout<<"1";
					if(s[2]=='D'&&S[2]=='F' || s[2]=='F'&&S[2]=='D') cout<<"1";
					else if(s[2]=='A'&&S[2]=='B' || s[2]=='B'&&S[2]=='A') cout<<"1";
					else if(s[2]=='B'&&S[2]=='C' || s[2]=='C'&&S[2]=='B') cout<<"1";
					else cout<<"0";	
				} 
				else if(s[2]=='A'&&S[2]=='C' || s[2]=='C'&&S[2]=='A'){
					cout<<"1";
					if(s[2]=='D'&&S[2]=='F' || s[2]=='F'&&S[2]=='D') cout<<"1";
					else if(s[2]=='A'&&S[2]=='B' || s[2]=='B'&&S[2]=='A') cout<<"1";
					else if(s[2]=='B'&&S[2]=='C' || s[2]=='C'&&S[2]=='B') cout<<"1";
					else cout<<"0";	
				} 
				else{
					cout<<"0"<<"0";
				} 
			} 
			else cout<<"0"<<"0"<<"0";
		}
		else cout<<"0"<<"0"<<"0";
	}
	else cout<<"0"<<"0"<<"0"<<"0";
	return 0;
}
