#include <bits/stdc++.h>
using namespace std;
string xr,s,xx,s2;
char sj,s2j;
int main(){
	freopen("travel.in","a",stdin);
	freopen("travel.out","w",stdout);
	cin>>xr>>s>>xx>>s2;
	s=s[0]+s[1];
	sj=s[2];
	s2=s2[0]+s2[1];
	s2j=s2[2];
	if(xr==xx){
		cout<<"1";
		if(s==s2)cout<<"1";
		else{
			cout<<"000";
			return 0;
		}
		if((sj<='C'&&s2j<='C')||(sj>='D'&&s2j>='D'))cout<<"1";
		else{
			cout<<"00";
			return 0;
		}
		if(sj-s2j==1||sj-s2j==-1)cout<<"1";
		else cout<<"0";
	}
	else cout<<"0000";
	return 0;
}
