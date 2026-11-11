#include<bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx){
		cout<<"1";
		if(sr[0]==sx[0]&&sr[1]==sx[1]){
			cout<<"1";
			if(sr[2]=='A'){
				if(sx[2]=='B'){
					cout<<"11";
				}
				else if(sx[2]=='C'){
					cout<<"10";
				}
				else
					cout<<"00";
			}
			if(sr[2]=='B'){
				if(sx[2]=='C'||sx[2]=='A'){
					cout<<"11";
				}
				else
					cout<<"00";
			}
			if(sr[2]=='C'){
				if(sx[2]=='B'){
					cout<<"11";
				}
				else if(sx[2]=='A'){
					cout<<"10";
				}
				else
					cout<<"00";
			}
			if(sr[2]=='F'||sr[2]=='D'){
				if(sx[2]=='D'||sx[2]=='F'){
					cout<<"11";
				}
				else
					cout<<"00";
			}
		}
		else
			cout<<"000";
		
	}	
	else
		cout<<"0000";
	return 0;
} 
