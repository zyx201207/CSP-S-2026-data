#include<bits/stdc++.h>
using namespace std;
#define PID "travel"
#define FIN freopen(PID".in","r",stdin)
#define FOU freopen(PID".out","w",stdout)
string a,as,b,bs,ans="";

int main(){
	FIN;
	FOU;
	cin>>a>>as>>b>>bs;
	if(a==b) ans+='1';
	else{
		cout<<"0000";
		return 0;
	}
	if(as[0]==bs[0] && as[1]==bs[1]) ans+='1';
	else{
		cout<<"1000";
		return 0;
	}
	if((as[2]=='A' || as[2]=='B' || as[2]=='C') && (bs[2]=='A' || bs[2]=='B' || bs[2]=='C'))
		ans+='1';
	else if((as[2]=='D' || as[2]=='E') && (bs[2]=='D' || bs[2]=='E'))
		ans+='1';
	else{
		cout<<"1100";
		return 0;
	}
	if(abs((as[2]-'A')-(bs[2]-'A'))==1){
		ans+='1';
		cout<<ans;
	}else cout<<"1110";
	return 0;
}
