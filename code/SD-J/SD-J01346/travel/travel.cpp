#include<bits/stdc++.h>
using namespace std;
string rc,rs,xc,xs,ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>rc>>rs>>xc>>xs;
	if(rc!=xc){
		cout<<"0000"<<"\n";
		return 0;
	}else{
		ans+='1';
	}
	if(rs[0]==xs[0]&&rs[1]==xs[1]){
		ans+='1';
	}else{
		ans+='0';
		ans+='0';
		ans+='0';
		cout<<ans<<"\n";
		return 0;
	}
	if((rs[2]<='C'&&xs[2]<='C')||rs[2]>='D'&&xs[2]>='D'){
		ans+='1';
	}else{
		ans+='0';
		ans+='0';
		cout<<ans<<"\n";
		return 0;
	}
	if((rs[2]=='C'&&xs[2]=='A')||(rs[2]=='A'&&xs[2]=='C')){
		ans+='0';
	}else{
		ans+='1';
	}
	cout<<ans<<"\n";
	return 0;
}

