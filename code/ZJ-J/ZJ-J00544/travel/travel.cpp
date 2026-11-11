#include<bits/stdc++.h>
#define ioi ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
string ac,az,bc,bz;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ioi;
	cin>>ac>>az>>bc>>bz;
	if(ac==bc) cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(az[0]==bz[0] && az[1]==bz[1]) cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if(az[2]=='A'){
		if(bz[2]=='B') cout<<1<<1;
		else if(bz[2]=='C') cout<<1<<0;
		else cout<<0<<0;
	}
	else if(az[2]=='B'){
		if(bz[2]=='A' || bz[2]=='C') cout<<1<<1;
		else cout<<0<<0;
	}
	else if(az[2]=='C'){
		if(bz[2]=='B') cout<<1<<1;
		else if(bz[2]=='A') cout<<1<<0;
		else cout<<0<<0;
	}
	else if(az[2]=='D'){
		if(bz[2]=='E') cout<<1<<1;
		else cout<<0<<0;
	}
	else{
		if(bz[2]=='D') cout<<1<<1;
		else cout<<0<<0;
	}
	return 0;
}