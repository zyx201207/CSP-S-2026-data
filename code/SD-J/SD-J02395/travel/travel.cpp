#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	string s,c,ss,cc;
	cin>>s>>c>>ss>>cc;
	if(s!=ss){
		cout<<"0000";
	} 
	else if(c.substr(0,2)!=cc.substr(0,2)){
		cout<<"1000";
	}
	else if((c[2]<='C'&&cc[2]>'C')||(c[2]>'C'&&cc[2]<='C')){
		cout<<"1100";
	}
	else if(char(c[2]+1)!=cc[2]&&char(cc[2]+1)!=c[2]){
		cout<<"1110";
	}
	else{
		cout<<"1111";
	}
	return 0;
} 
//Trick||Treat!
