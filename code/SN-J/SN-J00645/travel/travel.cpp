//TYZ lizihan SN-J00645

#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	char a=s2[2],b=s4[2];
	if(s1!=s3)cout<<"0000";
	else if(s2[0]!=s4[0]||s2[1]!=s4[1])cout<<"1000";
	else if(a<='C'&&b>='D')cout<<"1100";
	else if((a=='A'&&b=='C')||(a=='C'&&b=='A'))cout<<"1110";
	else cout<<"1111";
	
	return 0;
}
