#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		if(d[0]==b[0]&&d[1]==b[1]){
			cout<<"1";
			if((b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')||(b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='A')||(b[2]=='B'&&d[2]=='C')||(b[2]=='C'&&d[2]=='B'))
				cout<<"11";
			else if((b[2]=='A'&&d[2]=='C')||(b[2]=='C'&&d[2]=='A'))
				cout<<"10";
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
