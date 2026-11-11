#include <bits/stdc++.h> 
using namespace std;
#define int long long
string c,z,h,u;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>z>>h>>u;
	if(c==h){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(z[0]==u[0] and z[1]==u[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}if(z[2]=='A' and u[2]=='B' or z[2]=='A' and u[2]=='C' or z[2]=='B' and u[2]=='A' or z[2]=='B' and u[2]=='C' or z[2]=='C' and u[2]=='A' or z[2]=='C' and u[2]=='B' or z[2]=='D' and u[2]=='E' or z[2]=='E' and u[2]=='D'){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}if(z[2]=='A' and u[2]=='B' or z[2]=='B' and u[2]=='A' or z[2]=='B' and u[2]=='C' or z[2]=='C' and u[2]=='B' or z[2]=='D' and u[2]=='E' or z[2]=='E' and u[2]=='D'){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}

