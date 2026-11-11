#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d,m;
	cin>>a>>b>>c>>d;
	if(a==c)cout<<"1";
	else {
		cout<<"0000";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1])cout<<"1";
	else cout<<0;
	if(b[2]=='A'&&d[2]=='B'){
		cout<<"11";
		return 0;
	}
	if(b[2]=='B'&&d[2]=='A'){
		cout<<"11";
		return 0;
	}
	if(b[2]=='B'&&d[2]=='C'){
		cout<<"11";
		return 0;
	}
	if(b[2]=='C'&&d[2]=='B'){
		cout<<"11";
		return 0;
	}
	if(b[2]=='D'&&d[2]=='E'){
		cout<<"11";
		return 0;
	}
	if(b[2]=='E'&&d[2]=='D'){
		cout<<"11";
		return 0;
	}
	if(b[2]=='A'&&d[2]=='C'){
		cout<<"10";
		return 0;
	}
	if(b[2]=='A'&&d[2]=='D'){
		cout<<"00";
		return 0;
	}
	if(b[2]=='A'&&d[2]=='E'){
		cout<<"00";
		return 0;
	}
	if(b[2]=='C'&&d[2]=='A'){
		cout<<"10";
		return 0;
	}
	if(b[2]=='C'&&d[2]=='D'){
		cout<<"00";
		return 0;
	}
	if(b[2]=='C'&&d[2]=='E'){
		cout<<"00";
		return 0;
	}
	return 0;
} 
