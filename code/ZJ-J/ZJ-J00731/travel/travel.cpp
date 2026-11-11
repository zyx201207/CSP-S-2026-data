#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool tc(string x,string y){
	if(x[2]=='D'&&y[2]=='F') return true;
	if(x[2]>='A'&&x[2]<='C'&&y[2]>='A'&&y[2]<='C') return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<"1";
			if(tc(b,d)){
				cout<<"1";
				char x=b[2],y=d[2];
				if(x>y) swap(x,y);
				if((x=='D'&&y=='F')||(x=='A'&&y=='B')||(x=='B'&&y=='C')) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}