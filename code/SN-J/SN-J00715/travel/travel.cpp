//zhang ye chen
//xian an shi yi xin zhong xue
//SN-J00715
#include <bits/stdc++.h>
using namespace std;
string r1,r,s1,s;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r1>>r>>s1>>s;
	if(r1==s1){
	cout<<"1";
	if(r[0]==s[0]&&r[1]==s[1]){
	cout<<"1";
	if((r[2]=='A'&&(s[2]=='B'||s[2]=='C'))||(r[2]=='B'&&(s[2]=='A'||s[2]=='C'))||(r[2]=='C'&&(s[2]=='A'||s[2]=='B'))||(r[2]=='D'&&s[2]=='E')||(r[2]=='E'&&s[2]=='D')){
	cout<<"1";
	if(r[2]-s[2]==-1||r[2]-s[2]==1) cout<<"1";
	else cout<<"0";
	}
	else cout<<"00";
    }
	else cout<<"000";
	}
	else cout<<"0000";

	return 0;
}
