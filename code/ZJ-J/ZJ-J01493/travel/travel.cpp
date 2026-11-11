#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cr,sr,cx,sx;
	cin>>cr>>sr>>cx>>sx;
	int crn=0,cxn=0;
	crn=(cr[0]-'0')*10+(cr[1]-'0');
	cxn=(cx[0]-'0')*10+(cx[1]-'0');
	if(cxn!=crn){
		cout<<"0000";
		return 0;
	}
	int srn=0,sxn=0;
	srn=(sr[0]-'0')*10+(sr[1]-'0');
	sxn=(sx[0]-'0')*10+(sx[1]-'0');
	if(srn!=sxn){
		cout<<"1000";
		return 0;
	}
	if((sr[2]=='A'||sr[2]=='B'||sr[2]=='C')&&(sx[2]=='F'||sx[2]=='D')){
		cout<<"1100";
		return 0;
	}
	if((sx[2]=='A'||sx[2]=='B'||sx[2]=='C')&&(sr[2]=='F'||sr[2]=='D')){
		cout<<"1100";
		return 0;
	}
	if((sx[2]=='A'&&sr[2]!='B')||(sx[2]=='B'&&sr[2]!='C'&&sr[2]!='A')||(sx[2]=='C'&&sr[2]!='B')||(sx[2]=='D'&&sr[2]!='F')||(sx[2]=='F'&&sr[2]!='D')){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
