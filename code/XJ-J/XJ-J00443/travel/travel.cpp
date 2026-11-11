#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long c,C,ss,SS;
	string s,S;
	cin>>c>>s>>C>>S;
	if(c==C){
		cout<<1;
		if(s[0]==S[0] && s[1]==S[1]){
			cout<<1;
			if(s[2]>'C' && S[2]>'C' || s[2]<='C' && S[2]<='C'){
				cout<<1;
				ss=s[2]+'1';
				SS=S[2]+'1';
				if(abs(ss-SS)==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<0<<0;
			}
		}
		else{
			cout<<0<<0<<0;
		}
	}
	else{
		cout<<0<<0<<0<<0;
	}
}
