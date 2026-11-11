#include <bits/stdc++.h>
using namespace std;
string x1,x2,ya,y2;
bool f=true;
int main () {
	ios::sync_with_stdio(0);cin.tie(NULL),cout.tie(NULL);
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	cin>>x1>>x2>>ya>>y2;
	if (x1==ya) cout<<1;
	else {
		cout<<0;f=false;
	}
	
	if (f)
	if (x2.substr(0,2)==y2.substr(0,2)) cout<<1;
	else {
		cout<<0;f=false;
	}
	else cout<<0;
	
	char x=x2[2],y=y2[2];
	if (f)
	if( (x=='D'&&y=='F')||(x=='F'&&y=='D')) cout<<1;
	else {
		if (x=='D'||x=='F'||y=='F'||y=='D') {
			cout<<0;
			f=false;
		}
		else {
			cout<<1;
		}
	}
	else cout<<0;
	
	if (f)
	if ((x=='F'&&y=='D')||(x=='D'&&y=='F')) cout<<1;
	else if ((x=='C'&&y=='B')||(x=='B'&&y=='C')) cout<<1;
	else if ((x=='A'&&y=='B')||(x=='B'&&y=='A')) cout<<1;
	else {
		cout<<0;
	}
	else cout<<0;
}