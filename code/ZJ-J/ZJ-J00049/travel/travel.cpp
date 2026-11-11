#include<bits/stdc++.h>
using namespace std;
#define FILENAME "travel"

string c[3],s[3];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen(FILENAME ".in","r",stdin);
	freopen(FILENAME ".out","w",stdout);

	cin>>c[1]>>s[1]>>c[2]>>s[2];

	if(c[1]==c[2]){
		cout<<1;
	} else{
		cout<<"0000";
		return 0;
	}
	if((s[1][0]==s[2][0]) && s[1][1]==s[2][1]){
		cout<<1;
	} else {
		cout<<"000";
		return 0;
	}
	int a=s[1][2],b=s[2][2];

	if(a=='F' || a=='D'){
		if(b=='D' || b=='F'){
			cout<<"11";
			return 0;
		} else {
			cout<<"00";
			return 0;
		}
	} else {
		if(b=='D' || b=='F'){
			cout<<"00";
			return 0;
		}
		else{
			cout<<1;
			if( abs(a-b)==1 ) cout<<1;
			else cout<<0;
		}
	}


	return 0;
}