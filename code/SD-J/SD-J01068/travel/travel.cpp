#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,ss,t,tt,ans="";
	cin>>s>>ss>>t>>tt;
	if(s==t){
		ans+='1';
	}
	else{
		ans+="0000";
		cout<<ans;
		return 0;
	}
	if(ss[0]==tt[0]&&ss[1]==tt[1]){
		ans+='1';
	}
	else{
		ans+="000";
		cout<<ans;
		return 0;
	}
	if((ss[2]<='C'&&tt[2]<='C')||(ss[2]>='D'&&tt[2]>='D')){
		ans+='1';
		if((ss[2]=='A'&&tt[2]=='C')||(ss[2]=='C'&&tt[2]=='A')){
			ans+='0';
		}
		else{
			ans+='1';
		}
	}
	else{
		ans+='0';
		ans+='0';
	}
	cout<<ans;
	return 0;
}
