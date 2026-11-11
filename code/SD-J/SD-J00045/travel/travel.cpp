#include<bits/stdc++.h>
using namespace std;
string s,q,r,t;
int ans,sna,asn,nsa;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>q>>r>>t;
	int ca=(s[0]-'0')*10+(s[1]-'0'),cb=(r[0]-'0')*10+(r[1]-'0');
	if(ca!=cb){
		cout<<"0000";
		return 0;
	}
	ans=1;
	int za=(q[0]-'0')*10+(q[1]-'0'),zb=(t[0]-'0')*10+(t[1]-'0');
	char cc=q[2],dd=t[2];
	if(za!=zb){
		cout<<"1000";
		return 0;
	}
	sna=1;
	if(cc=='A'){
		if(dd=='B'){
			cout<<"1111";
			return 0;
		}
		else if(dd=='C'){
			cout<<"1110";
			return 0;
		}
		else {
			cout<<"1100";
			return 0;
		}
	}
	else if(cc=='B'){
		if(dd=='A'||dd=='C'){
			cout<<"1111";
			return 0;
		}
		else {
			cout<<"1100";
			return 0;
		}
	}
	else if(cc=='C'){
		if(dd=='B'){
			cout<<"1111";
			return 0;
		}
		else if(dd=='A'){
			cout<<"1110";
			return 0;
		}
		else {
			cout<<"1100";
			return 0;
		}
	}
	else if(cc=='D'){
		if(dd=='F'){
			cout<<"1111";
			return 0;
		}
		else {
			cout<<"1100";
			return 0;
		}
	}
	else if(cc=='F'){
		if(dd=='D'){
			cout<<"1111";
			return 0;
		}
		else {
			cout<<"1100";
			return 0;
		}
	}
	return 0;
} 
