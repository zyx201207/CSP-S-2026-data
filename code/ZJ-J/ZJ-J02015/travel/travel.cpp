#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c)cout<<'1';
	else{
		cout<<"0000";
		return 0;
	}
	int x = (b[0]-'0')*10+(b[1]-'0'),r = (d[0]-'0')*10+(d[1]-'0');
	char x1 = b[2],r1 = d[2];
	if(x==r){
		cout<<'1';
	}
	else{
		cout<<"000";
		return 0;
	}
	if((x1>='A'&&x1<='C'&&r1>='A'&&r1<='C')||(x1>='E'&&x1<='F'&&x1>='E'&&x1<='F')){
		cout<<'1';
	}
	else{
		cout<<"00";
		return 0;
	}
	if((x1+1)==r1||(x1-1)==r1){
		cout<<'1';
	}
	else cout<<'0';
	return 0;
}