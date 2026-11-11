#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,e,f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b>>c>>d;
	if(a==c) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	e+=b[0]+b[1];
	f+=d[0]+d[1];
	if(e==f){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if((b[2]=='C'&&d[2]=='D')||(b[2]=='D'&&d[2]=='C')){
		cout<<"00";
		return 0;
	}
	else{
		cout<<"1";
	}
	if(abs(b[2]-d[2])==1){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
