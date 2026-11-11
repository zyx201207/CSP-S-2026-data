#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
/*
RP++RP++RP++RP++RP++
RP++RP++RP++RP++RP++
RP++RP++RP++RP++RP++
RP++RP++RP++RP++RP++
RP++RP++RP++RP++RP++
*/
bool fc(char a,char b){
	if((a=='D'&&b=='C')||(a=='C'&&b=='D'))return 1;
	else return 0;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	int cx=0,cy=0;
	cx=(c1[0]-'0')*10+(c1[1]-'0');
	cy=(c2[0]-'0')*10+(c2[1]-'0');
	if(cx==cy)cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	//if1
	cx=(s1[0]-'0')*10+s1[1]-'0';
	cy=(s2[0]-'0')*10+s2[1]-'0';
	if(cx==cy)cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	//if2
	if((s1[2]<'D'&&s2[2]<'D')||(s1[2]>'C'&&s2[2]>'C'))cout<<1;
	else {
		cout<<"00";
		return 0;
	}//if3
	if(abs(s1[2]-s2[2])==1&&!fc(s1[2],s2[2]))cout<<1;
	else{
		cout<<"0";
		return 0;
	}//if4
	return 0;
}
