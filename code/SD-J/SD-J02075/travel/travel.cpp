#include<bits/stdc++.h>
using namespace std;
int __=1;
string c1,c2,s1,s2;
void solve(){
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
		if((s1[2]<='C'&&s2[2]<='C')){
			cout<<"1";
			if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')) cout<<"0";
			else cout<<"1"; 
		}else if(s1[2]>'C'&&s2[2]>'C'&&s1[2]<='F'&&s2[2]<='F'){
			cout<<"11";
		}else cout<<"00";
	}else cout<<"000";
	}
	else cout<<"0000";
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//cin>>__;
	while(__--) solve();
	return 0;
}

