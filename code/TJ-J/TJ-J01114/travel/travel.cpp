#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(false);
	cout.tie(false);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(b[1]==d[1] && b[0]==d[0] &&a==c){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(b[1]==d[1] && b[0]==d[0] &&a==c &&((b[2]=='A'&& d[2]=='C') || (b[2]=='C'&& d[2]=='A') || (b[2]=='B'&& d[2]=='C') || (b[2]=='C'&& d[2]=='B') || (b[2]=='A'&& d[2]=='B') || (b[2]=='B'&& d[2]=='A') || (b[2]=='D'&& d[2]=='E') || (b[2]=='E'&& d[2]=='D'))){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(b[1]==d[1] && b[0]==d[0] &&a==c &&(b[2]=='B'&& d[2]=='C') || (b[2]=='C'&& d[2]=='B') || (b[2]=='A'&& d[2]=='B') || (b[2]=='B'&& d[2]=='A') || (b[2]=='D'&& d[2]=='E') || (b[2]=='E'&& d[2]=='D')){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
} 
