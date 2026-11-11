#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(a==c&&b[0]==d[0]&&b[1]==d[1]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(a==c&&b[0]==d[0]&&b[1]==d[1]&&((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))||((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F'))){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(a==c&&b[0]==d[0]&&b[1]==d[1]&&((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))||((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F'))){
		if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='A')||(b[2]=='B'&&d[2]=='C')||(b[2]=='C'&&d[2]=='B')||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}
	else{
		cout<<"0";
	}
	return 0;
} 
