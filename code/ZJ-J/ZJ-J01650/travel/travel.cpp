#include<bits/stdc++.h>
using namespace std;
string cr,cx,sr,sx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx)cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	if(sr[0]+sr[1]==sx[0]+sx[1])cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if(sr[2]=='A'&&sx[2]=='B'||sr[2]=='A'&&sx[2]=='C')cout<<"1";
	else if(sr[2]=='B'&&sx[2]=='A'||sr[2]=='B'&&sx[2]=='C')cout<<"1";
	else if(sr[2]=='C'&&sx[2]=='B'||sr[2]=='C'&&sx[2]=='A')cout<<"1";
	else if(sr[2]=='D'&&sx[2]=='F'||sr[2]=='F'&&sx[2]=='D'){
		cout<<"11";
		return 0;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(sr[2]=='A'&&sx[2]=='B'||sx[2]=='A'&&sr[2]=='B')cout<<"1";
	else if(sr[2]=='C'&&sx[2]=='B'||sx[2]=='C'&&sr[2]=='B')cout<<"1";
	else cout<<"0";
	return 0;
}
