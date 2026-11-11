#include<bits/stdc++.h>
using namespace std;
string ac,as,bc,bs;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>ac>>as>>bc>>bs;
	
	if(ac==bc){
		cout<<"1";
		if(as[0]==bs[0]&&as[1]==bs[1]){
			cout<<"1";
			if((as[2]<='C'&&bs[2]<='C')||(as[2]>'C'&&bs[2]>'C')){
				cout<<"1";
				if((as[2]=='A'&&bs[2]=='B')||(as[2]=='B'&&bs[2]=='A')) cout<<"1";
				else if((as[2]=='B'&&bs[2]=='C')||(as[2]=='C'&&bs[2]=='B')) cout<<"1";
				else if((as[2]=='D'&&bs[2]=='F')||(as[2]=='F'&&bs[2]=='D')) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	
	
	return 0;
}

