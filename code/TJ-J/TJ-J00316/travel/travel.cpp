#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a;
	string s;
	string n;
	string m;
	cin>>a>>n>>s>>m;
	if(a[0]==s[0]&&a[1]==s[1]){
		cout<<1;
		if(n[0]==m[0]&&n[1]==m[1]){
			cout<<1;
			if(n[2]=='F'){
				if(m[2]=='D'){
					cout<<1<<1;
				}
				else{
					cout<<0<<0;
					return 0;
				}
			}
			else if(n[2]=='D'){
				if(m[2]=='F'){
					cout<<1<<1;
				}
				else{
					cout<<0<<0;
					return 0;
				}
			}
			else if(n[2]=='C'){
				if(m[2]=='A'||m[2]=='B'){
					cout<<1;
					if(m[2]=='B'){
						cout<<1;
					}
					else{
						cout<<0;
						return 0;
					}
				}
				else{
					cout<<0<<0;
					return 0;
				}
			}
			else if(n[2]=='B'){
				if(m[2]=='A'||m[2]=='C'){
					cout<<1<<1;
				}
				else{
					cout<<0<<0;
					return 0;
				}
			}
			else if(n[2]=='A'){
				if(m[2]=='C'||m[2]=='B'){
					cout<<1;
					if(m[2]=='B'){
						cout<<1;
					}
					else{
						cout<<0;
						return 0;
					}
				}
				else{
					cout<<0<<0;
					return 0;
				}
			}
		}
		else{
			cout<<0<<0<<0;
			return 0;
		}
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	return 0;
} 
