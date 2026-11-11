#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1e5;
const int M=1e3+1e2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(a==c&&b[0]==d[0]&&b[1]==d[1]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	char x=b[2],y=d[2];
	if(a==c&&b[0]==d[0]&&b[1]==d[1]&&((x=='A'&&y=='B')||(x=='B'&&y=='C')||(x=='D'&&y=='F')||(x=='B'&&y=='A')||(x=='C'&&y=='B')||(x=='F'&&y=='D')||(x=='A'&&y=='C')||(x=='C'&&y=='A'))){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(a==c&&b[0]==d[0]&&b[1]==d[1]&&((x=='A'&&y=='B')||(x=='B'&&y=='C')||(x=='D'&&y=='F')||(x=='B'&&y=='A')||(x=='C'&&y=='B')||(x=='F'&&y=='D'))){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
