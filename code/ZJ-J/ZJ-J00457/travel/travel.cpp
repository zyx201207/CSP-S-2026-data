#include<iostream>
using namespace std;
int a,b,tc,td;
string c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>b>>d;
	tc=(c[0]-'0')*10+c[1];
	td=(d[0]-'0')*10+d[1];
	if (a==b){ 
		cout<<1;
		if (tc==td){
			cout<<1;
			if ((c[2]=='A' && d[2]=='B') || (c[2]=='B' && d[2]=='A') || (c[2]=='A' && d[2]=='C') || (c[2]=='B' && d[2]=='C') || (c[2]=='C' && d[2]=='A') || (c[2]=='C'&& d[2]=='B') || (c[2]=='D' && d[2]=='F') || (c[2]=='F' && d[2]=='D')) cout<<1;
			else cout<<0;
			if ((c[2]=='A' && d[2]=='B') || (c[2]=='B' && d[2]=='A') || (c[2]=='B' && d[2]=='C') || (c[2]=='C' && d[2]=='B') || (c[2]=='D' && d[2]=='F') ||(c[2]=='F' && d[2]=='D')) cout<<1;
			else cout<<0;
		} 
		else cout<<"000";
	}
	else cout<<"0000";
	
	
	
}
