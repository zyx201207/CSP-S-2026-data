#include<bits/stdc++.h>
using namespace std;
//杨耀杰   SN-J00808  西安翱翔中学 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,s1a,s2a;
	char s1b,s2b;
	cin>>c1>>s1a>>s1b>>c2>>s2a>>s2b;
	if(c1==c2){
		cout<<1;
			if(s1a==s2a){
				cout<<1;
				if(((s1b=='A'||s1b=='B'||s1b=='C')&&(s2b=='A'||s2b=='B'||s2b=='C'))||((s1b=='D'||s1b=='F')&&(s2b=='D'||s2b=='F'))){
					cout<<1;
					if((s1b=='B'||s2b=='B')||((s1b=='D'||s1b=='F')&&(s2b=='D'||s2b=='F'))){
						cout<<1;
					}
					else cout<<0;
				
				}
				else{
					cout<<0;
					cout<<0;
				}
			}
			else{
				cout<<0;
				cout<<0;
				cout<<0;
			}
		}
	else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}
	return 0;
}
