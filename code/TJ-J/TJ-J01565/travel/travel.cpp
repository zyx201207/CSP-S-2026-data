#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<'1';
	}else{
		cout<<"0000";
		return 0;
	}
	char y=b[2];
	char u=d[2];
	if(b[0]==d[0]&&b[1]==d[1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if((y=='A'&&u=='B')||(y=='B'&&u=='C')||(y=='D'&&u=='E')||(u=='A'&&y=='B')||(u=='D'&&y=='E')||(u=='D'&&y=='E')){
		cout<<"11";
	}else if((y=='A'&&u=='C')||(u=='A'&&y=='C')){
		cout<<"10";
	}else{
		cout<<"00";
	}
	return 0;
}
