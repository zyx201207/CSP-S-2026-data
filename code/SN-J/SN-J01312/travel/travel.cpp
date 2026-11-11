#include<bits/stdc++.h>
using namespace std;
freopen(travel.in,"r",stdin); 
freopen(travel.out,"w",stdout);
int main()
{
	int a,d;
	string s,f;
	cin>>a>>s>>d>>f;
	if(a==d&&a!=1&&a!=16&&d!=1&&d!=16){
		cout<<"1";
		if(s[0]==f[0]){
			if(s[1]==f[1]){
				cout<<"1";
				if(s[2]==f[2]){
					cout<<"00";
				}else if(s[2]=='A'||s[2]=='B'||s[2]=='C'){
					if(f[2]=='A'||f[2]=='B'||f[2]=='C'){
						cout<<"1";
						if(s[2]=='A'&&f[2]=='B'){
							cout<<"1";
						}else if(s[2]=='B'&&f[2]=='C'){
							cout<<"1";
						}else if(s[2]=='B'&&f[2]=='A'){
							cout<<"1";
						}else if(s[2]=='C'&&f[2]=='B'){
							cout<<"1";
						}else{
							cout<<"0";
						}
					}else{
						cout<<"00";
					}
				}else if(s[2]=='D'||s[2]=='f'){
					if(f[2]=='D'||f[2]=='f'){
						cout<<"1";
						if(s[2]=='F'&&f[2]=='D'){
							cout<<"1";
						}else if(s[2]=='D'&&f[2]=='F'){
							cout<<"1";
						}else {
							cout<<"0";
						}
					}else{
						cout<<"00";
					}
				}else{
					cout<<"00";
				}
				
			}else{
				cout<<"000";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	
	return 0;
 } 
