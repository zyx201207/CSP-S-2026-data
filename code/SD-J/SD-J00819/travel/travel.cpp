#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b>>c>>d;
	if(a==c&&a!="01"&&a!="16") cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(b[0]+b[1]==d[0]+d[1]) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(abs(b[2]-d[2])<=2){
		if(b[2]=='C'){
			if(d[2]=='D') cout<<0;
			else cout<<1;
		}
		else if(b[2]=='D'){
			if(d[2]=='C') cout<<0;
			else cout<<1;
		}
		else cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(abs(b[2]-d[2])==1||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')){
		if(b[2]=='C'){
			if(d[2]=='D') cout<<0;
			else cout<<1;
		}
		else if(b[2]=='D'){
			if(d[2]=='C') cout<<0;
			else cout<<1;
		}
		else cout<<1;
	}
	else cout<<0;
	return 0;
}
