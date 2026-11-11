#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool aa,bb,cc=true;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(s1[2]=='A' or s1[2]=='B' or s1[2]=='C') aa=true;
	else aa=false;
	if(s2[2]=='A' or s2[2]=='B' or s2[2]=='C') bb=true;
	else bb=false;
	if(c1==c2) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0] and s1[1]==s2[1]) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if(aa==bb) cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	if(!aa and !bb) cout<<"1";
	else if(s1[2]=='A' and s2[2]=='C') cout<<"0";
	else if(s1[2]=='C' and s2[2]=='A') cout<<"0";
	else cout<<"1";
	return 0;
}
