#include<bits/stdc++.h>
#define int long long
#define ioi ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl "\n"
using namespace std;
string s1,c1,s2,c2;
signed main(){
	ioi;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>c1>>s2>>c2;
	if(c1[2]=='D') c1[2]='E';
	if(c2[2]=='D') c2[2]='E';
	if(s1==s2) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	} 
	if(c1[0]==c2[0]&&c1[1]==c2[1]) cout<<"1";
	else{
		cout<<"000";
		return 0;
	} 
	if((c1[2]<='C'&&c2[2]<='C')||(c1[2]>'C'&&c2[2]>'C')) cout<<"1";
	else{
		cout<<"00";
		return 0;	
	}
	if(abs((int)(c1[2]-c2[2]))==1) cout<<"1";
	else cout<<"0";
	return 0;
}
