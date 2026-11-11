#include<bits/stdc++.h>
using namespace std;
string s,t,ss,tt;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>ss>>t>>tt;
	if(s!=t){
		cout<<"0000\n";
		return 0;
	}
	cout<<1;
	string sss="",ttt="";
	sss=sss+ss[0];
	sss=sss+ss[1];
	ttt=ttt+tt[0];
	ttt=ttt+tt[1];
	if(sss!=ttt){
		cout<<"000\n";
		return 0;
	}
	cout<<1;
	int u=ss[2]-'A',v=tt[2]-'A';
	if((u>2&&v<=2)||(v>2&&u<=2)){
		cout<<"00\n";
		return 0;
	}
	cout<<1;
	if(abs(u-v)==1){
		cout<<1<<"\n";
	}else{
		cout<<0<<"\n";
	}
}
