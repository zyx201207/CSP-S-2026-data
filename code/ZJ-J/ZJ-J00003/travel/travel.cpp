#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2;
string ans;
bool ok(char x){
	return x=='A'||x=='B'||x=='C';
}
void work(){
	if(c1==c2)ans+="1";
	else{
		ans+="0000";
		return;
	}
	if(s1.substr(0,2)==s2.substr(0,2))ans+="1";
	else{
		ans+="000";
		return;
	}
	if(ok(s1[2])==ok(s2[2]))ans+="1";
	else{
		ans+="00";
		return;
	}
	if(!ok(s1[2])||abs(int(s1[2]-s2[2]))==1)ans+="1";
	else ans+="0";
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	work();
	cout<<ans;
	return 0;
}
