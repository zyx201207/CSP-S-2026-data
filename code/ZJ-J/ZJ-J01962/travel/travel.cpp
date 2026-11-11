#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int main(){
	//Trick||Treat!
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]!=c2[0]||c1[1]!=c2[1]) cout<<"0000";
	else if(s1[0]!=s2[0]||s1[1]!=s2[1]) cout<<"1000";
	else if(s1[2]>'C'&&s2[2]>'C') cout<<"1111";
	else if(s1[2]<='C'&&s2[2]<='C'){
		if(abs(s1[2]-s2[2])==1) cout<<"1111";
		else cout<<"1110";
	}
	else cout<<"1100";
	return 0;
}
