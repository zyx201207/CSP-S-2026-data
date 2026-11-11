#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a[1]==c[1]){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(b[1]==d[1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(b[2]=='E'||b[2]=='D'){
		if(d[2]=='E'||d[2]=='D'){
			cout<<"1";
		}else{
			cout<<"00";
			return 0;
		}
	}else{
		if(d[2]!='E'&&d[2]!='D'){
			cout<<"1";
		}else{
			cout<<"00";
			return 0;
		}
	}
	if(b[2]=='E'||b[2]=='D'){
		if(d[2]=='E'||d[2]=='D'){
			cout<<"1";
		}else{
			cout<<"0";
			return 0;
		}
	}else{
		if(b[2]=='B'||d[2]=='B'){
			cout<<"1";
		}else{
			cout<<"0";
			return 0;
		}
	}
}
//Trick||Treat!