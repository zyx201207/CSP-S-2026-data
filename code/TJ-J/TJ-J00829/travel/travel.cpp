#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int n=3;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c)cout<<"1";
	else {
		cout<<"0000";
		return 0;
	}
	if(b[1]==d[1] || b[2]==d[2])cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if(((b[3]=='D' || b[3]=='F') && (d[3]=='A' || d[3]=='B' || d[3]=='C')) || ((d[3]=='D' || d[3]=='F') && (b[3]=='A' || b[3]=='B' || b[3]=='C'))){
		cout<<"00";
	}
	else cout<<"1";
	if((b[n]=='F' && d[n]=='D') || (b[n]=='D' && d[n]=='F') || (b[n]=='A' && d[n]=='B') || ((b[n]=='B' && d[n]=='A') || (b[n]=='B' && d[n]=='C') || (b[n]=='C' && d[n]=='B')))cout<<"1";
	return 0;
} 
