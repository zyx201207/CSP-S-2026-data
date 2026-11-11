#include<bits/stdc++.h>
using namespace std;
int main(){
	string q,w,e,r;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>q>>w>>e>>r;
	string u;
	if(q==e){
		u+='1';
	}else{
		u+='0';
	}
	if(u[0]=='1'&&w[0]==r[0]&&w[1]==r[1]){
		u+='1';
	}else{
		u+='0';
	}
	if(u[0]=='1'&&u[1]=='1'){
		if(w[2]=='A'&&r[2]=='B'||w[2]=='B'&&r[2]=='A'||w[2]=='A'&&r[2]=='C'||w[2]=='C'&&r[2]=='A'||w[2]=='C'&&r[2]=='B'||w[2]=='B'&&r[2]=='C'||w[2]=='D'&&r[2]=='F'||w[2]=='F'&&r[2]=='D'){
			u+='1';
		}else{
		u+='0';
	}
	}else{
		u+='0';
		}
	if(u[0]=='1'&&u[1]=='1'&&u[2]=='1'){
		if(w[2]=='A'&&r[2]=='B'||w[2]=='B'&&r[2]=='A'||w[2]=='B'&&r[2]=='C'||w[2]=='C'&&r[2]=='B'||w[2]=='D'&&r[2]=='F'||w[2]=='F'&&r[2]=='D'){
		u+='1';
		}else{
		u+='0';
		}
	}else{
		u+='0';
		}
	cout<<u;
	return 0;
} 
