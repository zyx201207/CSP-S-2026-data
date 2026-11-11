#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1,c2,c3,c4;
int flag=0; 
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3) cout<<'1';
	else{
		cout<<"0000";
		return 0;
	}
	if(c4[0]==c2[0]&&c4[1]==c2[1]) cout<<'1';
	else{
		cout<<"000";
		return 0;
	}
	if(c2[2]=='D'&&c4[2]=='F') flag=1,cout<<'1';
	else if(c2[2]=='F'&&c4[2]=='D') flag=1,cout<<'1';
	else if(c2[2]=='A'&&c4[2]=='B') flag=1,cout<<'1';
	else if(c2[2]=='B'&&c4[2]=='A') flag=1,cout<<'1';
	else if(c2[2]=='A'&&c4[2]=='C') cout<<'1';
	else if(c2[2]=='C'&&c4[2]=='A') cout<<'1';
	else if(c2[2]=='C'&&c4[2]=='B') flag=1,cout<<'1';
	else if(c2[2]=='B'&&c4[2]=='C') flag=1,cout<<'1';
	else cout<<'0';
	if(flag) cout<<'1';
	else cout<<'0';
	return 0;
}
