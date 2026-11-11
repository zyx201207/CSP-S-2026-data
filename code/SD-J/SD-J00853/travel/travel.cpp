#include<bits/stdc++.h> 
using namespace std;
int cr,cx;
string sr,sx;
int hr,hx;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	if(cr!=cx){
		cout<<"0000";
		return 0;
	}
	else cout<<"1";
	
	hr=(sr[0]-48)*10+(sr[1]-48);
	hx=(sx[0]-48)*10+(sx[1]-48);
	if(hr!=hx){
		cout<<"000";
		return 0;
	}
	else cout<<"1";
	
	if((sr[2]=='A'&&sx[2]=='B')||(sr[2]=='B'&&sx[2]=='A')||(sr[2]=='A'&&sx[2]=='C')||(sr[2]=='C'&&sx[2]=='A')||(sr[2]=='B'&&sx[2]=='C')||(sr[2]=='C'&&sx[2]=='B')||(sr[2]=='D'&&sx[2]=='F')||(sr[2]=='F'&&sx[2]=='D'))
		cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	
	if((sr[2]=='A'&&sx[2]=='B')||(sr[2]=='B'&&sx[2]=='A')||(sr[2]=='C'&&sx[2]=='B')||(sr[2]=='B'&&sx[2]=='C')||(sr[2]=='D'&&sx[2]=='F')||(sr[2]=='F'&&sx[2]=='D'))
	    cout<<"1";
	else cout<<"0";
	return 0;
}
