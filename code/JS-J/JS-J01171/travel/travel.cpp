#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000"<<'\n';
		return 0;
	}
	cout<<"1";
	if(b[0]==d[0]&&b[1]==d[1]){
		cout<<"1";
		char x=b[2],y=d[2];
		if(x>y)    swap(x,y);
		if('A'<=x&&x<='C'&&'A'<=y&&y<='C'){
			cout<<"1";
			if((x=='A'&&y=='B')||(x=='B'&&y=='C')){
				cout<<"1"<<'\n';
				return 0;
			}
			cout<<"0"<<'\n';
			return 0;
		}else if(x=='D'&&y=='F'){
			cout<<"11"<<'\n';
			return 0;
		}
		cout<<"00"<<'\n';
		return 0;
	}
	cout<<"000"<<'\n';     
	return 0;
}
