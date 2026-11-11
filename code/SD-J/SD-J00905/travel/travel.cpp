#include<bits/stdc++.h>
using namespace std;
string s,ss,c,cc;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>ss>>c>>cc;
	if(s!=c){
		cout<<"0000";
	}
	else if(ss.substr(0,2)!=cc.substr(0,2)){
		cout<<"1000";
	}
	else if((ss[2]=='D'||ss[2]=='F')^(cc[2]=='D'||cc[2]=='F')){
		cout<<"1100";
	}
	else if((ss[2]=='C'||ss[2]=='A')&&(cc[2]=='C'||cc[2]=='A')){
		cout<<"1110";
	}
	else cout<<"1111";
	return 0;
}
