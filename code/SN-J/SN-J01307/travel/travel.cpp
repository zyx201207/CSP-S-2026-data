#include<bits/stdc++.h>
using namespace std;
string a,b,a2,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>a2>>b2;
	if(a==a2) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	if(b[0]==b2[0]&&b[1]==b2[1]) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if((b[2]=='C'&&b2[2]=='D')||(b2[2]=='C'&&b[2]=='D')){
		cout<<"00";
		return 0;
	}
	else cout<<"1";
	if(abs(b[2]-b2[2])==1||abs(b[2]-b2[2])==0) cout<<"1";
	else{
		cout<<"0";
		return 0;
	};
	return 0;
}
