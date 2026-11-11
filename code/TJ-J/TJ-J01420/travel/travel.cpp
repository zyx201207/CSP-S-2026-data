#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	int x = -1,y = -1,z = -1;
	if(a==c){
		cout << 1;
		x = 1;
	}
	else{
		cout << 0;
		x = 0;
	}
	if(x==1&&(b[0]=d[0]&&b[1]==d[1])){
		y = 1;
		cout << 1;
	}
	else{
		y = 0;
		cout << 0;
	}
	if(y==1&&((b[2]=='A'&&d[2]=='B')||(b[2]=='A'&&d[2]=='C')||(b[2]=='B'&&d[2]=='C')||(b[2]=='D'&&d[2]=='F')||(b[2]=='B'&&d[2]=='A')||(b[2]=='C'&&d[2]=='A')||(b[2]=='C'&&d[2]=='B')||(b[2]=='F'&&d[2]=='D'))){
		z = 1;
		cout << 1;
	}
	else{
		cout << 0;
	}
	if(z==1&&((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='A')||(b[2]=='B'&&d[2]=='C')||(b[2]=='C'&&d[2]=='B')||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D'))){
		cout << 1;
	}
	else{
		cout << 0;
	}
	return 0;
}
