#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		cout<<1;
		if(a2[0]!=b2[0]||a2[1]!=b2[1]){
			cout<<"000\n";
			return 0;
		}
		cout<<1;
		if((a2[2]=='A'&&b2[2]=='B')||(a2[2]=='A'&&b2[2]=='C')||(a2[2]=='B'&&b2[2]=='A')||(a2[2]=='B'&&b2[2]=='C')||(a2[2]=='C'&&b2[2]=='A')||(a2[2]=='C'&&b2[2]=='B')||(a2[2]=='D'&&b2[2]=='F')||(a2[2]=='F'&&b2[2]=='D02 01C 02 01D')){
			cout<<1;
			if(a2[2]==(b2[2]-1)||a2[2]==b2[2]+1){
				cout<<1<<"\n";
				return 0;
			}
			cout<<0<<"\n";
			return 0;
		}
		else{
			cout<<"00\n";
			return 0;
		}
	}
	else{
		cout<<"0000\n";
		return 0;
	}
	return 0;
}
