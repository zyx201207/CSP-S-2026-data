#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	char x,y;
	int a;
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1) cout<<"1";
	else {
		cout<<"0000";
		return 0;
	}
	for(int i=0; i<2; i++) {
		x=a2[i];
		y=b2[i];
		if(x==y)a=1;
		else {
			a=0;
			break;
		}
	}
	if(a==1) cout<<"1";
	else {
		cout<<"000";
		return 0;
	}
	x=a2[2];
	y=b2[2];
	if(((x=='A' || x=='B' || x=='C')&&(y=='A' || y=='B' || y=='C'))||((x=='D' || x=='E')&&(y=='D' || y=='E')))cout<<"1";
	else {
		cout<<"00";
		return 0;
	}
	if((x=='A' && y=='B')||(x=='B' && y=='A')||(x=='C' && y=='B')||(x=='B' && y=='C')||(x=='D' && y=='E')||(x=='E' && y=='D')) cout<<"1";
	else {
		cout<<"0";
		return 0;
	}
	return 0;
}

